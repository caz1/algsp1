#include "stringSort.h"


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
	fstream fs_str;

	fs_str.open("ex1/input/input_strings.txt", ofstream::out); 
	genTestFile(fs_str, 1 << 13);

	fs_str.close();
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

void write_back(ofstream &ofs, vector<string> &A)
{
	for (int i = 0; i < A.size(); i++)
		ofs << A[i] << endl;
	A.clear();
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
