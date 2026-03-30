all: animal custArray linear

animal:
	$(MAKE) -C animal

custArray:
	$(MAKE) -C custArray

linear:
	$(MAKE) -C linear

run-custarray:
	$(MAKE) -C custArray test

run-linear:
	$(MAKE) -C linear test

clean:
	$(MAKE) -C animal clean
	$(MAKE) -C custArray clean
	$(MAKE) -C linear clean

.PHONY: all animal custArray linear run-custarray run-linear clean