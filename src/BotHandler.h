////
//// Created by Никита Ковтуненко on 20.02.2024.
////
//
//#ifndef ECHOBOT_BOTHANDLER_H
//#define ECHOBOT_BOTHANDLER_H
//#include <tgbot/tgbot.h>
//#include <string>
//#include <fun
//namespace Bot {
//
//    struct BotHandler {
//        TgBot::Bot bot;
//
//        explicit BotHandler(const std::string &  token = "6890090721:AAEPIeaQDBEwWCj51tsR2x9r01IJxn1KzUM"):bot{token}
//        {
//            bot.getEvents().onCommand("start", callbackStart);
////    bot.getEvents().onCommand("start", [&bot](TgBot::Message::Ptr message) {
////        bot.getApi().sendMessage(message->chat->id, "Hi!");
////    });
//            bot.getEvents().onAnyMessage();
//            try {
//                printf("Bot username: %s\n", bot.getApi().getMe()->username.c_str());
//                TgBot::TgLongPoll longPoll(bot);
//                while (true) {
//                    printf("Long poll started\n");
//                    longPoll.start();
//                }
//            } catch (TgBot::TgException& e) {
//                printf("error: %s\n", e.what());
//            }
//        }
//
//
//        static void callbackStart(TgBot::Message::Ptr message, const TgBot::Bot& bot )  {
//            TgBot::ReplyKeyboardMarkup::Ptr keyboard(new TgBot::ReplyKeyboardMarkup);
//            std::vector<TgBot::KeyboardButton::Ptr> rowButtons;
//            TgBot::KeyboardButton::Ptr button1(new TgBot::KeyboardButton);
//            button1->text = "Button 1";
//            rowButtons.push_back(button1);
//            TgBot::KeyboardButton::Ptr button2(new TgBot::KeyboardButton);
//            button2->text = "Button 2";
//            rowButtons.push_back(button2);
//            keyboard->keyboard.push_back(rowButtons);
//            bot.getApi().sendMessage(message->chat->id, "Choose an option:", false, 0, keyboard);
//        }
//
//        static void callbackAllMessage(TgBot::Message::Ptr message,const TgBot::Bot& bot) {
//            printf("User wrote %s\n", message->text.c_str());
//            if (StringTools::startsWith(message->text, "/start")) {
//                return;
//            }
//            //bot.getApi().sendMessage(message->chat->id, "Your message is: " + message->text);
//
//            bot.getApi().sendMessage(message->chat->id, "Привет Иванов Николай! Поздравляю с покупкой авто!Прямых дорог и без ментов !" );
//        }
//
//
//    };
//
//} // Bot
//
//#endif //ECHOBOT_BOTHANDLER_H
