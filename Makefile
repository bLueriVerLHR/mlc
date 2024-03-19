ARGS	:= -S -o test/main.S test/main.sy > .log

all: build

build:
	cargo build

run:
	cargo run \
	-- $(ARGS)