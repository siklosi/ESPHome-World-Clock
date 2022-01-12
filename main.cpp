// Auto generated code by esphome
// ========== AUTO GENERATED INCLUDE BLOCK BEGIN ===========
#include "esphome.h"
#include <Time.h>     //https://github.com/PaulStoffregen/Time
#include <Timezone.h> //https://github.com/JChristensen/Timezone
#include <TM1637Display.h>
#include <NTPClient.h>
#include <WiFiUdp.h>
using namespace esphome;
using std::isnan;
using std::max;
using std::min;
using namespace switch_;
using namespace light;
logger::Logger *logger_logger;
wifi::WiFiComponent *wifi_wificomponent;
ota::OTAComponent *ota_otacomponent;
api::APIServer *api_apiserver;
using namespace api;
using namespace number;
preferences::IntervalSyncer *preferences_intervalsyncer;
template_::TemplateSwitch *template__templateswitch;
template_::TemplateNumber *display_intensity;
number::NumberStateTrigger *number_numberstatetrigger;
Automation<float> *automation_3;
neopixelbus::NeoPixelRGBLightOutput<NeoEsp8266UartMethodBase<NeoEsp8266UartSpeed800Kbps, NeoEsp8266Uart<UartFeature1, NeoEsp8266UartContext>, NeoEsp8266UartNotInverted>> *neopixelbus_neopixelbuslightoutputbase;
light::AddressableLightState *light_addressablelightstate;
light::AddressableColorWipeEffect *light_addressablecolorwipeeffect;
light::AddressableColorWipeEffect *light_addressablecolorwipeeffect_2;
light::RandomLightEffect *light_randomlighteffect;
light::RandomLightEffect *light_randomlighteffect_2;
light::PulseLightEffect *light_pulselighteffect;
light::PulseLightEffect *light_pulselighteffect_2;
light::PulseLightEffect *light_pulselighteffect_3;
light::FlickerLightEffect *light_flickerlighteffect;
light::FlickerLightEffect *light_flickerlighteffect_2;
light::AddressableRainbowLightEffect *light_addressablerainbowlighteffect;
light::AddressableRainbowLightEffect *light_addressablerainbowlighteffect_2;
light::AddressableFlickerEffect *light_addressableflickereffect;
light::AddressableFlickerEffect *light_addressableflickereffect_2;
mdns::MDNSComponent *mdns_mdnscomponent;
globals::GlobalsComponent<bool> *display_status;
Automation<> *automation_2;
globals::GlobalVarSetAction<globals::GlobalsComponent<bool>> *globals_globalvarsetaction_2;
Automation<> *automation;
globals::GlobalVarSetAction<globals::GlobalsComponent<bool>> *globals_globalvarsetaction;
#define yield() esphome::yield()
#define millis() esphome::millis()
#define micros() esphome::micros()
#define delay(x) esphome::delay(x)
#define delayMicroseconds(x) esphome::delayMicroseconds(x)
// ========== AUTO GENERATED INCLUDE BLOCK END ==========="
int dt;
int prev_brightnest=true;
int i = 0;
bool res;
int scolon = 0;
int period = 500;
unsigned long time_now = 0;
WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP, "europe.pool.ntp.org", 0, 60000);
TM1637Display display1(D6, D5);
TM1637Display display2(D6, D0);
TM1637Display display3(D6, D7);
TM1637Display display4(D6, D1);
TM1637Display display5(D6, D2);
TM1637Display display6(D6, D3);

TimeChangeRule CEST = {"CEST", Last, Sun, Mar, 2, 120}; // Central European Time (Kragujevac)
TimeChangeRule CET = {"CET ", Last, Sun, Oct, 3, 60};   // Central European Time (Kragujevac)
Timezone CE(CEST, CET);
// Australia Eastern Time Zone (Sydney, Melbourne)
TimeChangeRule aEDT = {"AEDT", First, Sun, Oct, 2, 660}; // UTC + 11 hours
TimeChangeRule aEST = {"AEST", First, Sun, Apr, 3, 600}; // UTC + 10 hours
Timezone ausET(aEDT, aEST);
// United Kingdom (London, Belfast)
TimeChangeRule BST = {"BST", Last, Sun, Mar, 1, 60}; // British Summer Time
TimeChangeRule GMT = {"GMT", Last, Sun, Oct, 2, 0};  // Standard Time
Timezone UK(BST, GMT);
// US Pacific Time Zone (Las Vegas, Los Angeles)
TimeChangeRule usPDT = {"PDT", Second, Sun, Mar, 2, -420};
TimeChangeRule usPST = {"PST", First, Sun, Nov, 2, -480};
Timezone usPT(usPDT, usPST);
// US Eastern Time Zone (New York, Detroit)
TimeChangeRule usEDT = {"EDT", Second, Sun, Mar, 2, -240}; // Eastern Daylight Time = UTC - 4 hours
TimeChangeRule usEST = {"EST", First, Sun, Nov, 2, -300};  // Eastern Standard Time = UTC - 5 hours
Timezone usET(usEDT, usEST);
// Japan Standard Time (JST, does not observe DST) Tokyo
TimeChangeRule jst = {"JST", Last, Sun, Mar, 1, 540};
Timezone tzJST(jst);

int getTime(Timezone tz, time_t utc)
{
  TimeChangeRule *tcr;
  time_t t = tz.toLocal(utc, &tcr);
  int displaytime = (hour(t) * 100) + minute(t);
  return (displaytime);
}

void setup()
{
  display1.setBrightness(1);
  display1.clear();
  display2.setBrightness(1);
  display2.clear();
  display3.setBrightness(1);
  display3.clear();
  display4.setBrightness(1);
  display4.clear();
  display5.setBrightness(1);
  display5.clear();
  display6.setBrightness(1);
  display6.clear();
  // ========== AUTO GENERATED CODE BEGIN ===========
  // esp8266:
  //   board: d1_mini
  //   framework:
  //     version: 2.7.4
  //     source: ~3.20704.0
  //     platform_version: platformio/espressif8266 @ 2.6.3
  //   restore_from_flash: false
  //   board_flash_mode: dout
  esphome::esp8266::setup_preferences();
  // esphome:
  //   name: worldclock
  //   build_path: .esphome/build/worldclock
  //   platformio_options: {}
  //   includes: []
  //   libraries: []
  //   name_add_mac_suffix: false
  App.pre_setup("worldclock", __DATE__ ", " __TIME__, false);
  // switch:
  // light:
  // logger:
  //   id: logger_logger
  //   baud_rate: 115200
  //   tx_buffer_size: 512
  //   deassert_rts_dtr: false
  //   hardware_uart: UART0
  //   level: DEBUG
  //   logs: {}
  //   esp8266_store_log_strings_in_flash: true
  logger_logger = new logger::Logger(115200, 512, logger::UART_SELECTION_UART0);
  logger_logger->pre_setup();
  logger_logger->set_component_source("logger");
  App.register_component(logger_logger);
  // wifi:
  //   id: wifi_wificomponent
  //   domain: .local
  //   reboot_timeout: 15min
  //   power_save_mode: NONE
  //   fast_connect: false
  //   output_power: 20.0
  //   networks:
  //   - ssid: !secret 'wifi_ssid'
  //     password: !secret 'wifi_password'
  //     id: wifi_wifiap
  //     priority: 0.0
  //   use_address: worldclock.local
  wifi_wificomponent = new wifi::WiFiComponent();
  wifi_wificomponent->set_use_address("worldclock.local");
  wifi::WiFiAP wifi_wifiap = wifi::WiFiAP();
  wifi_wifiap.set_ssid("siklosi");
  wifi_wifiap.set_password("1602197825");
  wifi_wifiap.set_priority(0.0f);
  wifi_wificomponent->add_sta(wifi_wifiap);
  wifi_wificomponent->set_reboot_timeout(900000);
  wifi_wificomponent->set_power_save_mode(wifi::WIFI_POWER_SAVE_NONE);
  wifi_wificomponent->set_fast_connect(false);
  wifi_wificomponent->set_output_power(20.0f);
  wifi_wificomponent->set_component_source("wifi");
  App.register_component(wifi_wificomponent);
  // ota:
  //   password: !secret 'ota_password'
  //   id: ota_otacomponent
  //   safe_mode: true
  //   port: 8266
  //   reboot_timeout: 5min
  //   num_attempts: 10
  ota_otacomponent = new ota::OTAComponent();
  ota_otacomponent->set_port(8266);
  ota_otacomponent->set_auth_password("c501e537987ea2776d5d609c717ce8fa");
  ota_otacomponent->set_component_source("ota");
  App.register_component(ota_otacomponent);
  if (ota_otacomponent->should_enter_safe_mode(10, 300000))
    return;
  // api:
  //   id: api_apiserver
  //   port: 6053
  //   password: ''
  //   reboot_timeout: 15min
  api_apiserver = new api::APIServer();
  api_apiserver->set_component_source("api");
  App.register_component(api_apiserver);
  api_apiserver->set_port(6053);
  api_apiserver->set_password("");
  api_apiserver->set_reboot_timeout(900000);
  // number:
  // preferences:
  //   id: preferences_intervalsyncer
  //   flash_write_interval: 60s
  preferences_intervalsyncer = new preferences::IntervalSyncer();
  preferences_intervalsyncer->set_write_interval(60000);
  preferences_intervalsyncer->set_component_source("preferences");
  App.register_component(preferences_intervalsyncer);
  // switch.template:
  //   platform: template
  //   name: World Clock Time
  //   lambda: !lambda |-
  //     if (id(display_status) == true) {
  //       return true;
  //     } else {
  //       return false;
  //     }
  //   turn_on_action:
  //     then:
  //     - globals.set:
  //         id: display_status
  //         value: 'true'
  //       type_id: globals_globalvarsetaction
  //     trigger_id: trigger
  //     automation_id: automation
  //   turn_off_action:
  //     then:
  //     - globals.set:
  //         id: display_status
  //         value: 'false'
  //       type_id: globals_globalvarsetaction_2
  //     trigger_id: trigger_2
  //     automation_id: automation_2
  //   disabled_by_default: false
  //   id: template__templateswitch
  //   optimistic: false
  //   assumed_state: false
  //   restore_state: false
  template__templateswitch = new template_::TemplateSwitch();
  template__templateswitch->set_component_source("template.switch");
  App.register_component(template__templateswitch);
  App.register_switch(template__templateswitch);
  template__templateswitch->set_name("World Clock Time");
  template__templateswitch->set_disabled_by_default(false);
  // number.template:
  //   platform: template
  //   id: display_intensity
  //   name: World Clock Intensity (0-7)
  //   icon: mdi:brightness-5
  //   optimistic: true
  //   initial_value: 0.0
  //   min_value: 0.0
  //   max_value: 7.0
  //   step: 1.0
  //   update_interval: 4000ms
  //   restore_value: true
  //   on_value:
  //   - then: []
  //     automation_id: automation_3
  //     trigger_id: number_numberstatetrigger
  //   disabled_by_default: false
  //   mode: AUTO
  display_intensity = new template_::TemplateNumber();
  display_intensity->set_update_interval(4000);
  display_intensity->set_component_source("template.number");
  App.register_component(display_intensity);
  App.register_number(display_intensity);
  display_intensity->set_name("World Clock Intensity (0-7)");
  display_intensity->set_disabled_by_default(false);
  display_intensity->set_icon("mdi:brightness-5");
  display_intensity->traits.set_min_value(0.0f);
  display_intensity->traits.set_max_value(7.0f);
  display_intensity->traits.set_step(1.0f);
  display_intensity->traits.set_mode(number::NUMBER_MODE_AUTO);
  number_numberstatetrigger = new number::NumberStateTrigger(display_intensity);
  automation_3 = new Automation<float>(number_numberstatetrigger);
  automation_3->add_actions({});
  display_intensity->set_optimistic(true);
  display_intensity->set_initial_value(0.0f);
  display_intensity->set_restore_value(true);
  // light.neopixelbus:
  //   platform: neopixelbus
  //   type: GRB
  //   variant: ws2812
  //   pin: 2
  //   num_leds: 6
  //   name: World Clock RGB Light
  //   effects:
  //   - addressable_color_wipe:
  //       colors:
  //       - num_leds: 1
  //         random: true
  //         red: 1.0
  //         green: 1.0
  //         blue: 1.0
  //         white: 1.0
  //       add_led_interval: 100ms
  //       reverse: false
  //       name: Color Wipe
  //     type_id: light_addressablecolorwipeeffect
  //   - addressable_color_wipe:
  //       name: Color Wipe Effect With Custom Values
  //       add_led_interval: 5000ms
  //       reverse: false
  //       colors:
  //       - num_leds: 1
  //         random: true
  //         red: 1.0
  //         green: 1.0
  //         blue: 1.0
  //         white: 1.0
  //     type_id: light_addressablecolorwipeeffect_2
  //   - random:
  //       name: Slow Random Effect
  //       transition_length: 30s
  //       update_interval: 30s
  //     type_id: light_randomlighteffect
  //   - random:
  //       name: Fast Random Effect
  //       transition_length: 4s
  //       update_interval: 5s
  //     type_id: light_randomlighteffect_2
  //   - pulse:
  //       transition_length: 1s
  //       update_interval: 1s
  //       name: Pulse
  //     type_id: light_pulselighteffect
  //   - pulse:
  //       name: Fast Pulse
  //       transition_length: 500ms
  //       update_interval: 500ms
  //     type_id: light_pulselighteffect_2
  //   - pulse:
  //       name: Slow Pulse
  //       update_interval: 2s
  //       transition_length: 1s
  //     type_id: light_pulselighteffect_3
  //   - flicker:
  //       alpha: 0.95
  //       intensity: 0.015
  //       name: Flicker
  //     type_id: light_flickerlighteffect
  //   - flicker:
  //       name: Flicker Custom
  //       alpha: 0.95
  //       intensity: 0.015
  //     type_id: light_flickerlighteffect_2
  //   - addressable_rainbow:
  //       speed: 10
  //       width: 50
  //       name: Rainbow
  //     type_id: light_addressablerainbowlighteffect
  //   - addressable_rainbow:
  //       name: Rainbow Custom
  //       speed: 10
  //       width: 50
  //     type_id: light_addressablerainbowlighteffect_2
  //   - addressable_flicker:
  //       update_interval: 16ms
  //       intensity: 0.05
  //       name: Addressable Flicker
  //     type_id: light_addressableflickereffect
  //   - addressable_flicker:
  //       name: Flicker Effect With Custom Values
  //       update_interval: 100ms
  //       intensity: 0.25
  //     type_id: light_addressableflickereffect_2
  //   disabled_by_default: false
  //   restore_mode: RESTORE_DEFAULT_OFF
  //   gamma_correct: 2.8
  //   default_transition_length: 1s
  //   flash_transition_length: 0s
  //   id: light_addressablelightstate
  //   output_id: neopixelbus_neopixelbuslightoutputbase
  //   invert: false
  //   method:
  //     bus: 1
  //     async: false
  //     type: esp8266_uart
  neopixelbus_neopixelbuslightoutputbase = new neopixelbus::NeoPixelRGBLightOutput<NeoEsp8266UartMethodBase<NeoEsp8266UartSpeed800Kbps, NeoEsp8266Uart<UartFeature1, NeoEsp8266UartContext>, NeoEsp8266UartNotInverted>>();
  light_addressablelightstate = new light::AddressableLightState(neopixelbus_neopixelbuslightoutputbase);
  App.register_light(light_addressablelightstate);
  light_addressablelightstate->set_component_source("light");
  App.register_component(light_addressablelightstate);
  light_addressablelightstate->set_name("World Clock RGB Light");
  light_addressablelightstate->set_disabled_by_default(false);
  light_addressablelightstate->set_restore_mode(light::LIGHT_RESTORE_DEFAULT_OFF);
  light_addressablelightstate->set_default_transition_length(1000);
  light_addressablelightstate->set_flash_transition_length(0);
  light_addressablelightstate->set_gamma_correct(2.8f);
  light_addressablecolorwipeeffect = new light::AddressableColorWipeEffect("Color Wipe");
  light_addressablecolorwipeeffect->set_add_led_interval(100);
  light_addressablecolorwipeeffect->set_reverse(false);
  light_addressablecolorwipeeffect->set_colors({light::AddressableColorWipeEffectColor{
      .r = 255,
      .g = 255,
      .b = 255,
      .w = 255,
      .random = true,
      .num_leds = 1,
  }});
  light_addressablecolorwipeeffect_2 = new light::AddressableColorWipeEffect("Color Wipe Effect With Custom Values");
  light_addressablecolorwipeeffect_2->set_add_led_interval(5000);
  light_addressablecolorwipeeffect_2->set_reverse(false);
  light_addressablecolorwipeeffect_2->set_colors({light::AddressableColorWipeEffectColor{
      .r = 255,
      .g = 255,
      .b = 255,
      .w = 255,
      .random = true,
      .num_leds = 1,
  }});
  light_randomlighteffect = new light::RandomLightEffect("Slow Random Effect");
  light_randomlighteffect->set_transition_length(30000);
  light_randomlighteffect->set_update_interval(30000);
  light_randomlighteffect_2 = new light::RandomLightEffect("Fast Random Effect");
  light_randomlighteffect_2->set_transition_length(4000);
  light_randomlighteffect_2->set_update_interval(5000);
  light_pulselighteffect = new light::PulseLightEffect("Pulse");
  light_pulselighteffect->set_transition_length(1000);
  light_pulselighteffect->set_update_interval(1000);
  light_pulselighteffect_2 = new light::PulseLightEffect("Fast Pulse");
  light_pulselighteffect_2->set_transition_length(500);
  light_pulselighteffect_2->set_update_interval(500);
  light_pulselighteffect_3 = new light::PulseLightEffect("Slow Pulse");
  light_pulselighteffect_3->set_transition_length(1000);
  light_pulselighteffect_3->set_update_interval(2000);
  light_flickerlighteffect = new light::FlickerLightEffect("Flicker");
  light_flickerlighteffect->set_alpha(0.95f);
  light_flickerlighteffect->set_intensity(0.015f);
  light_flickerlighteffect_2 = new light::FlickerLightEffect("Flicker Custom");
  light_flickerlighteffect_2->set_alpha(0.95f);
  light_flickerlighteffect_2->set_intensity(0.015f);
  light_addressablerainbowlighteffect = new light::AddressableRainbowLightEffect("Rainbow");
  light_addressablerainbowlighteffect->set_speed(10);
  light_addressablerainbowlighteffect->set_width(50);
  light_addressablerainbowlighteffect_2 = new light::AddressableRainbowLightEffect("Rainbow Custom");
  light_addressablerainbowlighteffect_2->set_speed(10);
  light_addressablerainbowlighteffect_2->set_width(50);
  light_addressableflickereffect = new light::AddressableFlickerEffect("Addressable Flicker");
  light_addressableflickereffect->set_update_interval(16);
  light_addressableflickereffect->set_intensity(0.05f);
  light_addressableflickereffect_2 = new light::AddressableFlickerEffect("Flicker Effect With Custom Values");
  light_addressableflickereffect_2->set_update_interval(100);
  light_addressableflickereffect_2->set_intensity(0.25f);
  light_addressablelightstate->add_effects({light_addressablecolorwipeeffect, light_addressablecolorwipeeffect_2, light_randomlighteffect, light_randomlighteffect_2, light_pulselighteffect, light_pulselighteffect_2, light_pulselighteffect_3, light_flickerlighteffect, light_flickerlighteffect_2, light_addressablerainbowlighteffect, light_addressablerainbowlighteffect_2, light_addressableflickereffect, light_addressableflickereffect_2});
  neopixelbus_neopixelbuslightoutputbase->set_component_source("neopixelbus.light");
  App.register_component(neopixelbus_neopixelbuslightoutputbase);
  neopixelbus_neopixelbuslightoutputbase->add_leds(6, 2);
  neopixelbus_neopixelbuslightoutputbase->set_pixel_order(neopixelbus::ESPNeoPixelOrder::GRB);
  // socket:
  //   implementation: lwip_tcp
  // mdns:
  //   id: mdns_mdnscomponent
  //   disabled: false
  mdns_mdnscomponent = new mdns::MDNSComponent();
  mdns_mdnscomponent->set_component_source("mdns");
  App.register_component(mdns_mdnscomponent);
  // globals:
  //   id: display_status
  //   type: bool
  //   restore_value: false
  //   initial_value: 'true'
  display_status = new globals::GlobalsComponent<bool>(true);
  display_status->set_component_source("globals");
  App.register_component(display_status);
  template__templateswitch->set_state_lambda([=]() -> optional<bool>
                                             {
#line 37 "/config/world-clock.yaml"
      if (display_status->value() == true) {
        return true;
      } else {
        return false;
      } });
  automation_2 = new Automation<>(template__templateswitch->get_turn_off_trigger());
  globals_globalvarsetaction_2 = new globals::GlobalVarSetAction<globals::GlobalsComponent<bool>>(display_status);
  globals_globalvarsetaction_2->set_value(false);
  automation_2->add_actions({globals_globalvarsetaction_2});
  automation = new Automation<>(template__templateswitch->get_turn_on_trigger());
  globals_globalvarsetaction = new globals::GlobalVarSetAction<globals::GlobalsComponent<bool>>(display_status);
  globals_globalvarsetaction->set_value(true);
  automation->add_actions({globals_globalvarsetaction});
  template__templateswitch->set_optimistic(false);
  template__templateswitch->set_assumed_state(false);
  template__templateswitch->set_restore_state(false);
  // =========== AUTO GENERATED CODE END ============
  App.setup();
}

void loop()
{
  timeClient.update();
  time_t utc = timeClient.getEpochTime();
  App.loop();
  if (millis() >= time_now + period){
    time_now += period;
    if (prev_brightnest != id(display_intensity).state){
      prev_brightnest = id(display_intensity).state;
      display1.setBrightness(id(display_intensity).state);
      display2.setBrightness(id(display_intensity).state);
      display3.setBrightness(id(display_intensity).state);
      display4.setBrightness(id(display_intensity).state);
      display5.setBrightness(id(display_intensity).state);
      display6.setBrightness(id(display_intensity).state);
    }
    if (id(display_status) == false){
      display1.clear();
      display2.clear();
      display3.clear();
      display4.clear();
      display5.clear();
      display6.clear();
    }else{
      if (scolon == 0){
        dt = getTime(CE, utc);
        display1.showNumberDecEx(dt, 0b11100000, true); // Kragujevac
        dt = getTime(usPT, utc);
        display2.showNumberDecEx(dt, 0b11100000, true); // Los Angeles
        dt = getTime(usET, utc);
        display3.showNumberDecEx(dt, 0b11100000, true); // New York
        dt = getTime(UK, utc);
        display4.showNumberDecEx(dt, 0b11100000, true); // London
        dt = getTime(tzJST, utc);
        display5.showNumberDecEx(dt, 0b11100000, true); // Tokyo
        dt = getTime(ausET, utc);
        display6.showNumberDecEx(dt, 0b11100000, true); // Sydney
        scolon = 1;
      }else{
        dt = getTime(CE, utc);
        display1.showNumberDec(dt, true);
        dt = getTime(usPT, utc);
        display2.showNumberDec(dt, true);
        dt = getTime(usET, utc);
        display3.showNumberDec(dt, true);
        dt = getTime(UK, utc);
        display4.showNumberDec(dt, true);
        dt = getTime(tzJST, utc);
        display5.showNumberDec(dt, true);
        dt = getTime(ausET, utc);
        display6.showNumberDec(dt, true);
        scolon = 0;
      }
    }
  }
}
