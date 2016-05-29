#include <iostream>
#include <fstream>
using namespace std;


class BucketSort
{
	private:	
		int *BucketAry;
		int bucketSize;
		int minData;
		int maxData;
		int offset;
		char* inFile;
		char* outFile1;
		char* outFile2;
	
	public:	
		BucketSort(char* input, char* output1, char* output2)
		{
			inFile = input;
			outFile1 = output1;
			outFile2 = output2;
			findMinMax();
			bucketSize = maxData - minData + 1;
			offset = minData;
			BucketAry = new int[bucketSize];
			for(int i = 0; i < bucketSize; i++)
			{
				BucketAry[i] = 0;	
			}	
		}	
		
		int getIndex(int data)
		{
			return (data - offset);
		}
		
		void printBucketAry()
		{
			ofstream myoutFile2(outFile2);
			myoutFile2 << "Debugging output:\n";
			for(int i = 0; i < 19; i++)
			{
				myoutFile2<< i << "\t";
			}
			myoutFile2 << endl;
			for(int i = 0; i < 19; i++)
			{
				myoutFile2 << BucketAry[i] << "\t";
			}
			myoutFile2.close();
			return;
		}
		
		void printSortedData()
		{
			ofstream myoutFile1(outFile1);
			myoutFile1 << "Sorted list:\n";
			for(int i = 0; i < bucketSize; i++)
			{
				while(BucketAry[i] > 0)
				{
					myoutFile1 << i + offset << endl;
					BucketAry[i]--;
				}
			}
			myoutFile1.close();
			return;	
		}
		
		void fillBucket()
		{
			ifstream myFile(inFile);
			int item;
			while(myFile >> item)
			{
				BucketAry[getIndex(item)]++;
			}
			myFile.close();
			return;
		}
		
		void findMinMax()
		{
			int item, firstItem;
			ifstream myFile(inFile); 
			myFile >> firstItem;
			minData = firstItem;
			maxData = firstItem;
			while(myFile >> item)
			{
				if(item < minData)
				{
					minData = item;
				}
				if(item > maxData)
				{
					maxData = item;	
				}  
			}
			myFile.close();
			return;
		}
		
		~BucketSort()
		{
			delete[] BucketAry;
		}
			
};

int main(int argc, char* argv[])
{
	BucketSort myBucketAry(argv[1], argv[2], argv[3]);
	myBucketAry.fillBucket();
	myBucketAry.printBucketAry();
	myBucketAry.printSortedData();
}
