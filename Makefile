all: clean tada68

clean:
	rm output/*

build-latest:
	docker build -t qmk:latest .

tada68: build-latest
	docker run  -v $(CURDIR)/output:/output -v $(CURDIR)/tada68:/qmk/keyboards/tada68/keymaps/magicmicky:ro -e keyboard=tada68 -e keymap=magicmicky -e output=bin -ti qmk 
