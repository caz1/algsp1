#include "mySort.h"


string rand_str(){
	string temp = "";
	int length = rand() % 16 + 1;

	for (int i = 0; i < length; i++)
		temp += charset[rand() % 62];
	return temp;
}

void genTestFile(fstream &ofs, int num)
{
	for (int i = 0; i < num; i++)
		ofs << rand_str() << endl;
}

void config()
{
#ifdef _WIN32
	system("md ex1\\input");
	system("md ex1\\output\\bubble_sort");
	system("md ex1\\output\\heap_sort");
	system("md ex1\\output\\merge_sort");
	system("md ex1\\output\\quick_sort");
	system("md ex1\\output\\shell_sort");

	system("md ex2\\input");
	system("md ex2\\output\\insert_sort");
	system("md ex2\\output\\quick_sort");
	system("md ex2\\output\\merge_sort");
	system("md ex2\\output\\radix_sort");
	system("md ex2\\output\\counting_sort");



#elif linux  
	system("mkdir ex1/input");
	system("mkdir ex1/output");
	system("mkdir ex1/output/shell_sort");
	system("mkdir ex1/output/bubble_sort");
	system("mkdir ex1/output/heap_sort");
	system("mkdir ex1/output/merge_sort");
	system("mkdir ex1/output/quick_sort");

	system("mkdir ex2/input");
	system("mkdir ex2/output");
	system("mkdir ex2/output/insert_sort");
	system("mkdir ex2/output/quick_sort");
	system("mkdir ex2/output/merge_sort");
	system("mkdir ex2/output/radix_sort");
	system("mkdir ex2/output/counting_sort");

#endif
	fstream fs_str, fs_digit;

	fs_str.open("ex1/input/input_strings.txt", ofstream::out); 
	fs_digit.open("ex2/input/input_num.txt", ofstream::out);
	genTestFile(fs_str, 1 << 13);
	for (int i = 0; i < 1 << 13; i++)
		fs_digit << rand() % MAX + 1 << endl;

	fs_str.close();
	fs_digit.close();

}

void init(ifstream &ifs, int size, vector<string> &A)
{
	for (int j = 0; j < size; j++)
	{
		string temp;
		ifs >> temp;
		A.push_back(temp);
	}
}

void init(ifstream &ifs, int size, unsigned short *A)
{
	for (int i = 0; i < size; i++)
		ifs >> A[i];
}

void write_back(ofstream &ofs, vector<string> &A)
{
	for (int i = 0; i < A.size(); i++)
		ofs << A[i] << endl;
	A.clear();
}

void write_back(ofstream &ofs, unsigned short *A, int length)
{
	for (int i = 0; i < length; i++)
		ofs << A[i] << endl;
}

void test()
{
	ifstream ifs;
	ofstream ofs, time;
	ifs.open("ex1/input/input_strings.txt");
	clock_t begin, end;

	for (int i = 2; i <= 12; i += 2)
	{
		vector<string> A;
		/****
		bubble sort
		*******/
		string filename = "ex1/output/bubble_sort/result_";
		filename += to_string(i);
		filename += ".txt";
		ofs.open(filename);
		filename = "ex1/output/bubble_sort/time.txt";
		time.open(filename, ofstream::app);
		init(ifs, 1 << i, A);
		begin = clock();
		bubbleSort(A);
		end = clock();
		time << "it takes " << end - begin << "us to sort " << (1 << i) << "strings" << endl;
		write_back(ofs, A);
		ofs.close();
		time.close();
		ifs.seekg(ifs.beg);
		/*****
		heap sort
		******/
		filename = "ex1/output/heap_sort/result_";
		filename += to_string(i);
		filename += ".txt";
		ofs.open(filename);
		filename = "ex1/output/heap_sort/time.txt";
		time.open(filename, ofstream::app);
		init(ifs, 1 << i, A);
		begin = clock();
		heapSort(A);
		end = clock();
		time << "it takes " << end - begin << "us to sort " << (1 << i) << "strings" << endl;
		write_back(ofs, A);
		time.close();
		ifs.seekg(ifs.beg);
		ofs.close();
		/*****
		merge sort
		******/
		filename = "ex1/output/merge_sort/result_";
		filename += to_string(i);
		filename += ".txt";
		ofs.open(filename);
		filename = "ex1/output/merge_sort/time.txt";
		time.open(filename, ofstream::app);
		init(ifs, 1 << i, A);
		begin = clock();
		mergeSort(A, 0, A.size() - 1);
		end = clock();
		time << "it takes " << end - begin << "us to sort " << (1 << i) << "strings" << endl;
		write_back(ofs, A);
		time.close();
		ifs.seekg(ifs.beg);
		ofs.close();
		/*****
		quick sort
		******/
		filename = "ex1/output/quick_sort/result_";
		filename += to_string(i);
		filename += ".txt";
		ofs.open(filename);
		filename = "ex1/output/quick_sort/time.txt";
		time.open(filename, ofstream::app);
		init(ifs, 1 << i, A);
		begin = clock();
		mySort<vector<string> >::quickSort(A, 0, A.size() - 1);
		end = clock();
		time << "it takes " << end - begin << "us to sort " << (1 << i) << "strings" << endl;
		write_back(ofs, A);
		time.close();
		ifs.seekg(ifs.beg);
		ofs.close();
		/*****
		shell sort
		******/
		filename = "ex1/output/shell_sort/result_";
		filename += to_string(i);
		filename += ".txt";
		ofs.open(filename);
		filename = "ex1/output/shell_sort/time.txt";
		time.open(filename, ofstream::app);
		init(ifs, 1 << i, A);
		begin = clock();
		shellSort(A);
		end = clock();
		time << "it takes " << end - begin << "us to sort " << (1 << i) << "strings" << endl;
		write_back(ofs, A);
		ifs.seekg(ifs.beg);
		time.close();
		ofs.close();
	}

	// here is for num 
	ifs.close();
	ifs.open("ex2/input/input_num.txt");

	for (int i = 3; i <= 13; i += 2)
	{
		unsigned short *B = new unsigned short[1 << i];
		/****
		insert sort
		*******/
		string filename = "ex2/output/insert_sort/result_";
		filename += to_string(i);
		filename += ".txt";
		ofs.open(filename);
		filename = "ex2/output/insert_sort/time.txt";
		time.open(filename, ofstream::app);
		init(ifs, 1 << i, B);
		begin = clock();
		mySort<unsigned short*>::insertSort(B, 1 << i, 1);
		end = clock();
		time << "it takes " << end - begin << "us to sort " << (1 << i) << "numbers" << endl;
		write_back(ofs, B, 1 << i);
		ofs.close();
		time.close();
		ifs.seekg(ifs.beg);
		/*****
		quick sort
		******/
		filename = "ex2/output/quick_sort/result_";
		filename += to_string(i);
		filename += ".txt";
		ofs.open(filename);
		filename = "ex2/output/quick_sort/time.txt";
		time.open(filename, ofstream::app);
		init(ifs, 1 << i, B);
		begin = clock();
		mySort<unsigned short *>::quickSort(B, 0, (1 << i) - 1);
		end = clock();
		time << "it takes " << end - begin << "us to sort " << (1 << i) << "numbers" << endl;
		write_back(ofs, B, 1 << i);
		ifs.seekg(ifs.beg);
		time.close();
		ofs.close();
		/*****
		merge sort
		******/
		filename = "ex2/output/merge_sort/result_";
		filename += to_string(i);
		filename += ".txt";
		ofs.open(filename);
		filename = "ex2/output/merge_sort/time.txt";
		time.open(filename, ofstream::app);
		init(ifs, 1 << i, B);
		begin = clock();
		mergeSort(B, 0, (1 << i) - 1);
		end = clock();
		time << "it takes " << end - begin << "us to sort " << (1 << i) << "numbers" << endl;
		write_back(ofs, B, 1 << i);
		time.close();
		ifs.seekg(ifs.beg);
		ofs.close();
		/******
		counting sort
		******/
		filename = "ex2/output/counting_sort/result_";
		filename += to_string(i);
		filename += ".txt";
		ofs.open(filename);
		filename = "ex2/output/counting_sort/time.txt";
		time.open(filename, ofstream::app);
		unsigned short *C = new unsigned short[1 << i];
		memset(C, 0, (1 << i) * sizeof(unsigned short));
		init(ifs, 1 << i, B);
		begin = clock();
		countingSort(B, C, 1 << i, 0, 16);
		end = clock();
		time << "it takes " << end - begin << "us to sort " << (1 << i) << "numbers" << endl;
		write_back(ofs, C, 1 << i);
		time.close();
		ifs.seekg(ifs.beg);
		ofs.close();
		/******
		radix sort
		******/
		filename = "ex2/output/radix_sort/result_";
		filename += to_string(i);
		filename += ".txt";
		ofs.open(filename);
		filename = "ex2/output/radix_sort/time.txt";
		time.open(filename, ofstream::app);
		memset(B, 0, (1 << i) * sizeof(unsigned short));
		init(ifs, 1 << i, B);
		memset(C, 0, (1 << i) * sizeof(unsigned short));
		begin = clock();
		radixSort(B, C, 1 << i);
		end = clock();
		time << "it takes " << end - begin << "us to sort " << (1 << i) << "numbers" << endl;
		write_back(ofs, C, 1 << i);
		time.close();
		ifs.seekg(ifs.beg);
		ofs.close();
	}
}



int main()
{
	srand(time(NULL));
	config();
	test();
#ifdef _WIN32
	system("pause");
#endif
}
