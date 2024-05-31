#include <stdio.h>
#include <tgbot/tgbot.h>
#include "Logger.h"

int main() {
//    TgBot::Bot bot("6890090721:AAEPIeaQDBEwWCj51tsR2x9r01IJxn1KzUM");
//    Call c;
//    bot.getEvents().onCommand("start", c);
////    bot.getEvents().onCommand("start", [&bot](TgBot::Message::Ptr message) {
////        bot.getApi().sendMessage(message->chat->id, "Hi!");
////    });
//    bot.getEvents().onAnyMessage([&bot](TgBot::Message::Ptr message) {
//        printf("User wrote %s\n", message->text.c_str());
//        if (StringTools::startsWith(message->text, "/start")) {
//            return;
//        }
//        //bot.getApi().sendMessage(message->chat->id, "Your message is: " + message->text);
//        bot.getApi().sendMessage(message->chat->id, "Привет Иванов Николай! Поздравляю с покупкой авто!Прямых дорог и без ментов !" );
//    });
//
//
//
//    try {
//        printf("Bot username: %s\n", bot.getApi().getMe()->username.c_str());
//        TgBot::TgLongPoll longPoll(bot);
//        while (true) {
//            printf("Long poll started\n");
//            longPoll.start();
//        }
//    } catch (TgBot::TgException& e) {
//        printf("error: %s\n", e.what());
//    }
    std::cout << PROJECT_PATH << std::endl;
    Log::Logger::getInstance().setOutputFile("/Logs.txt");
    Log::Logger::getInstance().setLogLevel(Log::LogLevel::LogInfo);
    Log::Logger::getInstance() << "Hello world" << " How are you ? ";

    return 0;
}