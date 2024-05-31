//
// Created by Никита Ковтуненко on 22.02.2024.
//
#ifndef ECHOBOT_LOGGER_H
#define ECHOBOT_LOGGER_H
#include <iostream>
#include <string>
#include <fstream>
#include "../cmake-build-debug/config.h"
#include <ctime>
#include <mutex>

namespace Log {

    enum class LogLevel{
        LogDebug,
        LogInfo,
        LogWarning,
        LogRelease,
        LogError
    };

    class FileDeliter
    {
    public:
        void operator() (std::ofstream * stream){
            stream->close();
            delete stream;
        }
    };

    class Logger {

        std::unique_ptr<std::ofstream,FileDeliter> _stream ;
        LogLevel _level;
        std::string _outFile;
        std::mutex mtx;


        Logger(): _stream{new std::ofstream,FileDeliter()},
#ifdef BUILD_MODE_DEBUG
        _level{LogLevel::LogDebug}
#elif BUILD_MODE_RELEASE
        _level{LogLevel::LogRelease}
#endif
        {}
        ~Logger() = default;
        Logger(const Logger&) {}

        const char* getLogLevel()
        {
            switch (_level) {
                case LogLevel::LogDebug:
                    static const  char* deb = "[DEBUG]";
                    return deb;

                case LogLevel::LogInfo:
                    static const  char* info = "[INFO]";
                    return info;

                case LogLevel::LogWarning:
                    static const  char* warn = "[WARNING]";
                    return warn;

                case LogLevel::LogRelease:
                    static const  char* work = "[WORK]";
                    return work;
                case LogLevel::LogError:
                    static const  char* error = "[ERROR]";
                    return error;

                default: break;
            }
        }

    public:

        static Logger& getInstance()
        {
            static auto log = Logger();
            return  log;
        }

        void setLogLevel(LogLevel level)
        {
            std::unique_lock<std::mutex> lock(mtx);
            _level = level;
        }

        void setOutputFile(const std::string& path)
        {
            std::unique_lock<std::mutex> lock(mtx);
            _outFile = path;
        }

        LogLevel logLevel()
        {
            std::unique_lock<std::mutex> lock(mtx);
            return _level;
        }

        Logger & operator<<(const std::string& str)
        {
            std::unique_lock<std::mutex> lock(mtx);
            _stream->open(PROJECT_PATH + _outFile,std::ios::out | std::ios::app | std::ios::ate);

            if (_stream->is_open())
            {
                auto now = std::chrono::system_clock::now();
                auto time = std::chrono::system_clock::to_time_t(now);
                char buffer[80];
                std::strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", std::localtime(&time));
                *_stream << getLogLevel() <<' ' <<'[' << buffer << ']' << ' ' << str << '\n';
                _stream->close();
            }
            return getInstance();
        }

    };

} // Log

#endif //ECHOBOT_LOGGER_H
