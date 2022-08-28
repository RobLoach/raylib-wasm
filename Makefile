c:
	$(MAKE) -C examples/c

native:
	cmake -B runtimes/native/build -S runtimes/native
	$(MAKE) -C runtimes/native/build

test: native c
	runtimes/native/build/raylib-wasm examples/c/build/cart.wasm

clean:
	rm -rf examples/c/build
	rm -rf runtimes/native/build
