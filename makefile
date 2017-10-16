make:   driver.cpp person.cpp backpack.cpp days.cpp
	g++ -Wall driver.cpp person.cpp backpack.cpp days.cpp -o survive -g

run:    driver.cpp survive
	./survive data.txt

clean:
	rm survive
	rm -f *.o
