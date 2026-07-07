all clean:
	make -C src $(MAKECMDGOALS)

.PHONY: build-debug
build-debug:
	BUILD_TYPE=Debug make