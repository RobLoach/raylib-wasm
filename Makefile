test: wasi c
	runtimes/wasi/build/raylib-wasm examples/c/build/cart.wasm

c:
	$(MAKE) -C examples/c

wasi:
	cmake -B runtimes/wasi/build -S runtimes/wasi
	$(MAKE) -C runtimes/wasi/build

clean:
	rm -rf examples/c/build
	rm -rf runtimes/wasi/build
