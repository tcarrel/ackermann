all:

ack: ack.cpp
	g++ ack.cpp -o ack

acka: acka.cpp
	g++ acka.cpp -o ack

clean:
	rm -f ack acka
