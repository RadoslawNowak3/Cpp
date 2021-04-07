#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <stdint.h>
#include <assert.h>
#include <string>
#include <iostream>
#include <bitset>
#include <cmath>
#include <string>
#include <fstream>

const int SYMBOLS = 4;
const int STATES = 5;
const int RANGE = 32;

static char* read_file(char const* filename, size_t* out_size) {
	FILE* f = fopen(filename, "r");
	if (!f)
		std::cout << "file not found: %s\n" << filename << std::endl;

	fseek(f, 0, SEEK_END);
	size_t size = ftell(f);
	fseek(f, 0, SEEK_SET);

	char* buf = new char[size];
	if (fread(buf, size, 1, f) != 1)
		std::cout << "read error" << std::endl;
	fclose(f);
	if (out_size)
		*out_size = size;

	return buf;
}

void write_file(char const* filename, std::string data) {
	std::ofstream file;
	file.open(filename);
	if (!file)
		std::cout << "file not found: %s\n" << filename << std::endl;
	file << data;
	file.close();
}
/*
void calc_freqs(int* freqs, char* in_bytes, size_t in_size)
{
	for (int i = 0; i < SYMBOLS; i++)
		freqs[i] = 0;
	for (size_t i = 0; i < in_size; i++)
		freqs[in_bytes[i]-65]++;
}
*/

/*
void scale_freqs(int* freqs, int* scaledfreqs, size_t in_size)
{
	for (int i = 0; i < SYMBOLS; i++)
		scaledfreqs[i] = freqs[i] * ceil(RANGE / (int)in_size);
}
*/
void print_probs(double* probs)
{
	for (int i = 0; i < SYMBOLS; i++)
		std::cout << probs[i] << " ";
	std::cout << std::endl;
}

void print_freqs(int* freqs)
{
	for (int i = 0; i < RANGE; i++)
		std::cout << freqs[i] << " ";
}

double* calc_probs(int* freqs, int RANGE) // oblicza prawdopodobienstwa
{
	double* probs = new double[SYMBOLS];
	for (int i = 0; i < SYMBOLS; i++)
	{
		probs[i] = ((double)freqs[i] / (double)RANGE);
	}
	return probs;
}

int* makeK(int* freqs) //k[s] wyznacza maksymalna liczbę bitow, o ktora mozna przesunac stan x tak, aby wciąż nalezal do {Ls, . . . , 2Ls − 1}
{
	std::cout << "WYPISUJE K" << std::endl;
	int* k = new int[SYMBOLS];
	for (int i = 0; i < SYMBOLS; i++)
	{
		k[i] = STATES - (int)floor((int)log2(freqs[i]));
		std::cout << k[i] << " ";
	}
	std::cout << std::endl;
	return k;
}

int* makeNB(int* freqs, int* k) // tablica pomocnicza wykorzystywana przy okreslaniu liczby bitow o ktore nalezy przesunac aktualny stan
{
	std::cout << "WYPISUJE NB" << std::endl;
	int* nb = new int[SYMBOLS];
	for (int z = 0; z < SYMBOLS; z++)
	{
		nb[z] = (((k[z]) << (STATES + 1)) - ((freqs[z]) << (k[z])));
		std::cout << nb[z] << " ";
	}
	return nb;
}
int toInt(char c)
{
	return (int)c - 65;
}

int* makeStart(int* freqs) // start[s] okresla gdzie rozpoczyna się obszar nowego symbolu
{
	std::cout << "WYPISUJE START" << std::endl;
	int* start = new int[SYMBOLS];
	for (int j = 0; j < SYMBOLS; j++)
	{
		start[j] = ((-1) * (freqs[j]));
		for (int i = 0; i < j; i++)
		{
			start[j] = start[j] + freqs[i];
		}
		std::cout << start[j] << " ";
	}
	std::cout << std::endl;
	return start;
}
int * makeEncodingTable(const int* freqs, const char * symbols, const int * start)
{
	int s;
	int* encodingTable = new int[RANGE];
	int* next = new int[SYMBOLS];
	for (int i = 0; i < SYMBOLS; i++)
		next[i] = freqs[i];
	for (int x = RANGE; x < 2 * RANGE; x++)
	{
		s = toInt(symbols[x - RANGE]);
		encodingTable[(start[s]) + ((next[s])++)] = x;
	}
	std::cout << std::endl;
	return encodingTable;
}
std::string useBits(const int x, const int nbBits)  // zwraca najmniej znaczace bity
{
	std::bitset<64> b(x);
	std::string bin = b.to_string<char, std::char_traits<char>, std::allocator<char> >();
	std::string lsb;
	int s = bin.size() - 1;
	for (int i = 0; i < nbBits; i++)
	{
		lsb += bin[s - nbBits + i];
	}
	return lsb;
}
char* createSymbolTable(int* freqs, char* alphabet) { // tablica zawierajaca elementy alfabetu w okreslonych ilosciach
	char* symbols = new char[RANGE];
	int counter = 0;
	for (int i = 0; i < SYMBOLS; i++)
	{
		for (int j = 0; j < freqs[i]; j++)
		{
			symbols[counter] = alphabet[i];
			counter++;
		}
	}
	return symbols;
}

void spread_fast(char* symbols, int* freqs, char* alphabet) { // tasowanie tablicy symboli
	int pos = 0;
	int step = (RANGE >> 1) + (RANGE >> 3) + 3;
	int mask = RANGE - 1;
	for (int sym = 0; sym < SYMBOLS; sym++) {
		for (int i = 0; i < freqs[sym]; i++)
		{
			symbols[pos] = alphabet[sym];
			pos = (pos + step) & mask;
		}
	}
}

struct Decoder
{
	char symbol;
	int nbBits;
	int newX;
};

int powx(int a, int b)
{
	int result = 1;
	if (b == 0)
		return 1;
	for (int i = 0; i < b; i++)
		result *= a;
	return result;
}

int bintodec(int* n)
{
	int sum = 0;
	int power = 0;
	int size = sizeof(n) / sizeof(n[0]);
	for (size; size > 0; size--)
	{
		if (n[size] == 1)
			sum += powx(2, power);
		power++;
	}
	return sum;
}



int main() {
	size_t in_size;
	double* probs;
	char alphabet[4] = { 'A','B','C','D' };
	int freqs[SYMBOLS] = { 12,8,4,8 };
	int curr;
	int nbBits;
	int x;
	std::string encodedData = "";
	char* input = read_file("Text.txt", &in_size);

	std::cout << "WYPISUJE DANE DO ZAKODOWANIA" << std::endl;
	for (size_t i = 0; i < in_size; i++)
		std::cout << input[i];

	std::cout << std::endl;
	std::cout << "WYPISUJE TABLICE SYMBOLI" << std::endl;
	char* symbols = createSymbolTable(freqs, alphabet);
	for (int i = 0; i < RANGE; i++)
		std::cout << symbols[i];
	std::cout << std::endl;

	std::cout << "WYPISUJE TABLICE SYMBOLI PO WYKONANIU FUNKCJI SPREAD" << std::endl;
	spread_fast(symbols, freqs, alphabet);
	for (int i = 0; i < RANGE; i++)
		std::cout << symbols[i];
	std::cout << std::endl;

	// int scaledfreqs[SYMBOLS];
	// std::qsort(symbols, in_size, sizeof(char), compare);
	//print_freqs(freqs);
	//std::cout << std::endl;
	//scale_freqs(freqs, scaledfreqs, in_size);
	//print_freqs(scaledfreqs, SYMBOLS);
	std::cout << "WYPISUJE TABLICE PRAWDOPODOBIENSTW" << std::endl;
	probs = calc_probs(freqs, RANGE);
	print_probs(probs);

	//PRZYGOTOWANIE DO KODOWANIA
	int* start = makeStart(freqs);
	int *k = makeK(freqs);
	int* nb = makeNB(freqs, k);
	int* encodingTable = makeEncodingTable(freqs, symbols, start);
	x = encodingTable[0];

	std::cout << "WYPISUJE ENCODINGTABLE" << std::endl;
	for (int i = 0; i < RANGE; i++)
		std::cout << encodingTable[i] << " ";

	// KODOWANIE
	for (size_t i = 0; i < in_size; i++)
	{
		curr = toInt(input[i]);
		nbBits = (((x)+(nb[curr])) >> (STATES + 1));
		encodedData += useBits(x, nbBits);
		x = encodingTable[(start[curr]) + (x >> nbBits)];
	}

	std::cout << std::endl;
	std::cout << "ZAKODOWANE DANE" << std::endl;
	std::cout << encodedData << std::endl;
	std::cout << "OSTATECZNY STAN DEKODERA" << std::endl;
	std::cout << x << std::endl;
	write_file("Zakodowane.txt", encodedData);

	delete[]k;
	delete[]nb;
	delete[]probs;
	delete[]start;
	delete[]encodingTable;
	// DEKODOWANIE

	Decoder dekoder;
	Decoder decodingTable[RANGE];
	int X = x - RANGE;
	int temp;
	size_t read_size;
	int c = 0, g = 0;
	int buf[2 * RANGE];
	size_t readdata = 0;
	std::string decoded = "";

	int next[SYMBOLS];
	std::copy(std::begin(freqs), std::end(freqs), std::begin(next));

	char* decoding_input = read_file("Zakodowane.txt", &read_size);
	std::cout << "WYPISUJE WCZYTANE DANE" << std::endl;
	for (size_t i = 0; i < read_size; i++)
		std::cout << decoding_input[i];
	std::cout << std::endl;
	// TABLICA DEKODOWANIA
	for (int i = 0; i < RANGE; i++)
	{
		dekoder.symbol = symbols[i];
		temp = next[toInt(dekoder.symbol)]++;
		dekoder.nbBits = STATES - (int)floor(log2(temp));
		dekoder.newX = ((temp << dekoder.nbBits) - RANGE);
		decodingTable[i] = dekoder;
	}
	std::cout << "WYPISUJE DECODINGTABLE" << std::endl;
	for (int i = 0; i < RANGE; i++)
	{
		std::cout << decodingTable[i].symbol << " " << decodingTable[i].nbBits << " " << decodingTable[i].newX << std::endl;
	}

	// DEKODOWANIE
	while (readdata < read_size)
	{
		dekoder = decodingTable[X];
		decoded += dekoder.symbol;
		g = c;
		for (c; c < g + dekoder.nbBits; c++)
		{
			if ((size_t)c == read_size)
				break;
			buf[c - g] = (int)decoding_input[c] - 48;
		}
		X = dekoder.newX + bintodec(buf);
		readdata += (size_t)dekoder.nbBits;
	}

	std::cout << "WYPISUJE ZDEKODOWANE DANE" << std::endl;
	std::cout << decoded;
}