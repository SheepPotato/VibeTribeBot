#include <iostream>
#include <fstream>
#include <string>
#include "sleepy_discord/websocketpp_websocket.h"

using namespace std;

class BaseClass : public SleepyDiscord::DiscordClient {
public:
    using SleepyDiscord::DiscordClient::DiscordClient;
    void onMessage(SleepyDiscord::Message message) {
        if (message.isMentioned(804960055186161675))
            sendMessage(message.channelID, "Sup <@" + message.author.ID + ">");
            
    }
};

string getToken(string path) {
    string token;
    ifstream tokenFile(path);
    getline(tokenFile, token);
    return token;
}

int main() {
    string path = "discord_token.txt";
    BaseClass client(getToken(path), 2);
    client.run();
}