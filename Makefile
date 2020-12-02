all: clean tada68

clean:
	rm -f output/*

build-latest:
	docker build -t qmk:latest .

tada68: clean build-latest
	docker run  -v $(CURDIR)/output:/output -v $(CURDIR)/tada68:/qmk/keyboards/tada68/keymaps/magicmicky:ro -e keyboard=tada68 -e keymap=magicmicky -e output=bin -ti qmk 

uno: clean build-latest
	docker run  -v $(CURDIR)/output:/output -v $(CURDIR)/uno:/qmk/keyboards/uno/keymaps/magicmicky:ro -e keyboard=uno -e keymap=magicmicky -e output=hex -ti qmk 


clean-flash:
	test -d /Volumes/TADA68\ \ /
	rm -rf /Volumes/TADA68\ \ /.Trashes/ /Volumes/TADA68\ \ /.fseventsd/ /Volumes/TADA68\ \ /._.Trashes /Volumes/TADA68\ \ /._FLASH.bin /Volumes/TADA68\ \ /FLASH.bin

flash-tada68: tada68 clean-flash
	cp ./output/tada68_magicmicky.bin /Volumes/TADA68\ \ /FLASH.bin
