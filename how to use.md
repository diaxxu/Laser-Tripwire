#  HOW TO USE

This project makes your ESP32 send you a Telegram message when someone breaks a laser beam. Like a mini security system 

---

##  What You Need

- ESP32  
- Laser pointer or laser module  
- LDR (photoresistor)  
- 10k ohm resistor  
- Wires + breadboard  
- Wi-Fi with internet  
- Telegram account  

---



### Wiring:
- Point the laser at the LDR  
- Connect LDR and 10k resistor like a voltage divider  



---

## 🔐 Secrets File

define ur `/secrets.h` 

```cpp
#define WIFI_SSID "your_wifi_name"
#define WIFI_PASS "your_wifi_password"
#define TELEGRAM_TOKEN "your_bot_token"
#define TELEGRAM_CHAT_ID "your_chat_id"
```

##  Telegram Setup
- Go to @BotFather

- Type /newbot → give it a name

- Copy the bot token

- Send a message to your new bot

- Go to this link (replace YOUR_TOKEN):

```
https://api.telegram.org/botYOUR_TOKEN/getUpdates
Copy your chat_id from the JSON
```



