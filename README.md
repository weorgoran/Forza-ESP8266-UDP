# Wireless XBox Forza 7 Display
An arduino based project, using an ESP8266 to wirelessly display telemetry data broadcast from XBox Forza 7.

Currently configured as an engine speed indicator and outputs to WS2812 LED string, however all data in the packet is available for use.

Demo can be seen [on instagram](https://www.instagram.com/p/CAkvRcDFVOZ/).

## Requirements:

* [Arduino ESP8266](https://github.com/esp8266/Arduino) for UDP support.

* [FastLED](https://github.com/FastLED/FastLED) for WS2812 support.

* Forza 7 on XBox One. This requires the UDP Broadcasting to be enabled and IP and port to be configured in the game. This is deep in the HUD menus.
