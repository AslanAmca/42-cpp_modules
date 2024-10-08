#include "PmergeMe.hpp"

// Orthodox Canonical Form
PmergeMe::PmergeMe(){};
PmergeMe::~PmergeMe(){};
PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
	(void)(other);
	return *this;
};
PmergeMe::PmergeMe(const PmergeMe &other)
{
	(void)(other);
};

// Vector sort functions
void PmergeMe::mergeInsertSortVector(std::vector<int> &container, int start, int end)
{
	if (start < end)
	{
		if ((end - start) < 10)
			insertSortVector(container, start, end);
		else
		{
			int newEnd = start + (end - start) / 2;
			mergeInsertSortVector(container, start, newEnd);
			mergeInsertSortVector(container, newEnd + 1, end);
			mergeSortVector(container, start, newEnd, end);
		}
	}
};

void PmergeMe::mergeSortVector(std::vector<int> &container, int start, int mid, int end)
{
	int i, j, k;

	std::vector<int> left(mid - start + 1);
	std::vector<int> right(end - mid);

	for (i = 0; i < (mid - start + 1); ++i)
		left[i] = container[start + i];
	for (j = 0; j < (end - mid); ++j)
		right[j] = container[mid + 1 + j];

	i = 0;
	j = 0;
	k = start;
	while (i < (mid - start + 1) && j < (end - mid))
	{
		if (left[i] <= right[j])
			container[k++] = left[i++];
		else
			container[k++] = right[j++];
	}

	while (i < (mid - start + 1))
		container[k++] = left[i++];
	while (j < (end - mid))
		container[k++] = right[j++];
};

void PmergeMe::insertSortVector(std::vector<int> &container, int start, int end)
{
	for (int index = start; index <= end; index++)
	{
		int hold = container[index];
		int j = index - 1;
		for (; j >= start && container[j] > hold; --j)
			container[j + 1] = container[j];
		container[j + 1] = hold;
	}
};

// Deque sort functions
void PmergeMe::mergeInsertSortDeque(std::deque<int> &container, int start, int end)
{
	if (start < end)
	{
		if ((end - start) < 10)
			insertSortDeque(container, start, end);
		else
		{
			int newEnd = start + (end - start) / 2;
			mergeInsertSortDeque(container, start, newEnd);
			mergeInsertSortDeque(container, newEnd + 1, end);
			mergeSortDeque(container, start, newEnd, end);
		}
	}
};

void PmergeMe::mergeSortDeque(std::deque<int> &container, int start, int mid, int end)
{
	int i, j, k;

	std::deque<int> left(mid - start + 1);
	std::deque<int> right(end - mid);

	for (i = 0; i < (mid - start + 1); ++i)
		left[i] = container[start + i];
	for (j = 0; j < (end - mid); ++j)
		right[j] = container[mid + 1 + j];

	i = 0;
	j = 0;
	k = start;
	while (i < (mid - start + 1) && j < (end - mid))
	{
		if (left[i] <= right[j])
			container[k++] = left[i++];
		else
			container[k++] = right[j++];
	}

	while (i < (mid - start + 1))
		container[k++] = left[i++];
	while (j < (end - mid))
		container[k++] = right[j++];
};

void PmergeMe::insertSortDeque(std::deque<int> &container, int start, int end)
{
	for (int index = start; index <= end; index++)
	{
		int hold = container[index];
		int j = index - 1;
		for (; j >= start && container[j] > hold; --j)
			container[j + 1] = container[j];
		container[j + 1] = hold;
	}
};

// Calcualte time functions
void PmergeMe::runVector(std::vector<int> &container)
{
	mergeInsertSortVector(container, 0, container.size() - 1);
};

void PmergeMe::runDeque(std::deque<int> &container)
{
	mergeInsertSortDeque(container, 0, container.size() - 1);
};

// vector ve deque üzerinde sıralama işlemlerini ölçen bir yardımcı fonksiyondur.
void PmergeMe::calculateTime(std::vector<int> &vector, std::deque<int> &deque, double &vecTime, double &deqTime)
{
	// Zaman ölçümünü başlatmak için std::clock_t türünde bir değişken olan start tanımlanır ve mevcut saat değeri ile başlatılır.
	std::clock_t start = std::clock();
	runVector(vector);

	// Sıralama işlemi tamamlandıktan sonra, tekrar saat değeri alınarak işlemin tamamlandığı zamanı belirlemek için end değişkenine atanır.
	std::clock_t end = std::clock();

	// Başlangıç ve bitiş zamanları arasındaki fark hesaplanır ve mikro saniye cinsinden geçen süre elde edilir.
	// Hesaplar dışarıdan verilen değişkene atanır.
	double elapsed = static_cast<double>(end - start) / (CLOCKS_PER_SEC / 1000000.0);
	vecTime = elapsed;

	start = std::clock();
	runDeque(deque);
	end = std::clock();
	elapsed = static_cast<double>(end - start) / (CLOCKS_PER_SEC / 1000000.0);
	deqTime = elapsed;
}

// Bir vektör ve bir de deque'i ekrana yazdırmak için kullanılır.
void PmergeMe::print(std::vector<int> &vec, std::deque<int> &deq)
{
	std::cout << "Vector : ";
	for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;

	std::cout << "Deque : ";
	for (std::deque<int>::iterator it = deq.begin(); it != deq.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;
}

// Bir aralığın orta noktasını hesaplar ve bu değeri döndürür.
// Aralığı ikiye bölerek merge sort algoritmasında kullanılacak olan bölünmüş dizileri elde ediyoruz.
int PmergeMe::midPoint(int start, int end)
{
	return (start + (end - start) / 2);
}