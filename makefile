all: pig luhn beer vowel

numRange: _num_range/numRange.c
	gcc -Wall -pedantic -std=c99 _num_range/numRange.c -o bin/Range
	./bin/Range

numRewrite: _num_rewrite/numRewrite.c
	gcc -Wall -pedantic -std=c99 _num_rewrite/numRewrite.c -o bin/Rewrite
	./bin/Rewrite

gpa: _gpa_calculator/gpaCalculator.c
	gcc -Wall -pedantic -std=c99 _gpa_calculator/gpaCalculator.c -o bin/GPA
	./bin/GPA

vowel: _vowel_replacement/vowel.c
	gcc -Wall -pedantic -std=c99 _vowel_replacement/vowel.c -o bin/Vowel
	./bin/Vowel

beer: _beer_on_the_wall/beerOnTheWall.c
	gcc -Wall -pedantic -std=c99 _beer_on_the_wall/beerOnTheWall.c -o bin/Beer
	./bin/Beer

pig: _game_of_pig/a1PIG.c
	gcc -Wall -pedantic -std=c99 _game_of_pig/a1PIG.c -o bin/Game_of_Pig
	./bin/Game_of_Pig

luhn: _luhns_algorithm/LUHN.c
	gcc -Wall -pedantic -std=c99 _luhns_algorithm/LUHN.c -o bin/Luhn
	./bin/Luhn

clean:
	rm bin/*