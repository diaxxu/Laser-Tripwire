#  ESP32 Laser Tripwire with Telegram Alert

A spy-style laser security system built with an ESP32. When someone crosses the laser beam, you get an instant Telegram message. Perfect for room security, prank traps, or just flexing your skills.

##  Features

- Laser beam + photoresistor detection
- Telegram bot alerts

- Fast and clean response system

##  Hardware Required

| Component         | Qty |
|------------------|-----|
| ESP32             | 1   |
| Laser Module      | 1   |
| LDR (photoresistor)| 1   |
| 10k Resistor      | 1   |
| Breadboard + Wires| —   |
| WiFi              | yes |

##  How it works

1. Laser constantly hits the LDR.
2. ESP32 monitors light level via analog pin.
3. When the beam is broken (e.g., someone walks through), the LDR reading drops.
4. ESP32 sends an alert to Telegram using a bot you create.

##  Telegram Bot Setup

1. Message [@BotFather](https://t.me/BotFather)
2. `/newbot` → give it a name + username
3. Save the API token
4. Get your `chat_id` via this link after sending a message to the bot:  
   `https://api.telegram.org/bot<YOUR_TOKEN>/getUpdates`

##  Setup

### 1. Clone the repo

```bash
git clone https://github.com/yourusername/laser-tripwire.git
cd laser-tripwire
