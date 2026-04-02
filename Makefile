all: animal custArray linear

animal:
	$(MAKE) -C animal

custArray:
	$(MAKE) -C custArray

linear:
	$(MAKE) -C linear
trees:
	$(MAKE) -C trees

run-custarray:
	$(MAKE) -C custArray test

run-linear:
	$(MAKE) -C linear test

run-trees:
	$(MAKE) -C trees test

clean:
	$(MAKE) -C animal clean
	$(MAKE) -C custArray clean
	$(MAKE) -C linear clean
	$(MAKE) -C trees clean

.PHONY: all animal custArray linear trees run-custarray run-linear run-trees clean