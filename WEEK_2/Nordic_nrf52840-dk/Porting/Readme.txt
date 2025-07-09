contiki structure :

contiki-ng/
├── arch/
│   ├── cpu/
│   │   ├── arm/
│   │   │   ├── cortex-m4/         # Cortex-M4 generic code
│   │   │   ├── nrf/               # NRF family-specific code
│   │   │   │   ├── clock.c        # Clock/timer driver
│   │   │   │   ├── rtimer-arch.c  # Real-time timer driver
│   │   │   │   ├── startup-gcc.c  # Startup code
│   │   │   │   ├── gpio.c         # GPIO driver
│   │   │   │   ├── radio/         # Radio driver (802.15.4)
│   │   │   │   ├── Makefile
│
├── platform/
│   ├── nrf52840dk/
│   │   ├── contiki-conf.h         # Config: platform clock rate, radio config
│   │   ├── Makefile.include       # Board-specific build rules
│   │   ├── platform.c             # Board init: LED, button
│   │   ├── sensors.c              # Optional: sensors driver
│
├── os/                            # Contiki core
├── examples/                      # Try hello-world

Porting Steps — For nRF52840 DK:

1) CPU support:

	arch/cpu/arm/nrf/

	clock.c: Implements Contiki’s clock API using NRF’s RTC or SysTick.

	rtimer-arch.c: Precise real-time timer using NRF hardware timers.

	gpio.c: LED/Button support.

	radio/: The tricky part: either use the 802.15.4 radio driver or BLE (needs integration).

	Contiki’s event loop & timers depend on these drivers!

2) Platform support:

	platform/nrf52840dk/

	contiki-conf.h: Here you define:


	#define PLATFORM_HAS_LEDS 1
	#define PLATFORM_CONF_RADIO nrf52840_radio_driver
	#define CLOCK_CONF_SECOND 32768
	platform.c: Init LEDs, buttons.

	Makefile.include: Board-specific build flags.
	
3) Radio driver:

	Out of the box, the nrf-802154 driver is used for 802.15.4.
	This means you can run IPv6 6LoWPAN mesh protocols.

	For BLE:

	Contiki-NG does NOT have a full BLE link layer implementation.

	You’d need to:

	Use Nordic’s SoftDevice BLE stack OR

	Integrate NimBLE (Apache) OR

	Use Zephyr instead (recommended for real BLE).

4) Build system:

	Makefile.include sets compiler flags for ARM Cortex-M4.

	You may use arm-none-eabi-gcc.

	Example build:
		cd examples/hello-world
		make TARGET=nrf52840dk BOARD=nrf52840dk
		
5) Flash & test:
	
		nrfjprog --program hello-world.hex --chiperase --reset
		nrfjprog --reset


