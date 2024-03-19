# sorting-alg-benchmark
A comprehensive C++ project benchmarking the performance of various sorting algorithms, including TimSort, IntroSort, MergeSort, QuickSort, and HeapSort, across different data distributions to understand their efficiency and behavior in diverse scenarios

## How to Run
0. Make sure you have installed `CMake`, `make`, and a C++ compiler (e.g., g++)
1. Clone the repository and navigate to the project directory
    ```bash
    git clone --recurse-submodules https://github.com/NTUCSRC/sorting-alg-benchmark.git
    cd sorting-alg-benchmark
    ```
2. Generate testing data
    ```
    cd data
    python3 generate.py
    ```
3. Run the following commands in the terminal:
    ```bash
    cd sorting-alg-benchmark
    mkdir build
    cd build
    cmake ..
    make
    ./SortingAlgorithmBenchmark <distribution> <number of elements>
    ```
## Performance Analysis

### Environment

- Processor: Intel(R) Core(TM) i5-1135G7 @ 2.40GHz
- Memory (RAM): 16GB
- Operating System: Ubuntu 20.04 LTS (Focal Fossa)
- Compiler: g++ (Ubuntu 9.4.0-1ubuntu1~20.04.2) 9.4.0

### Random Distribution
Description: Generates a list of random integers within a specified range. This distribution is useful for testing sorting algorithms under average, everyday conditions where the input order is completely unsorted and unpredictable.


![random dist](./data/images/image.png)
#### Perfromance @ 100 Elements
```
----------------------------------------------------------------------
Benchmark                            Time             CPU   Iterations
----------------------------------------------------------------------
InsertionSort/iterations:10      22843 ns        22730 ns           10
HeapSort/iterations:10           34397 ns        34460 ns           10
IntroSort/iterations:10           9730 ns         9700 ns           10
MergeSort/iterations:10          46933 ns        47020 ns           10
QuickSort/iterations:10           6889 ns         6870 ns           10
TimSort/iterations:10            18157 ns        18190 ns           10
```
#### Performance @ 1000 Elements
```
----------------------------------------------------------------------
Benchmark                            Time             CPU   Iterations
----------------------------------------------------------------------
InsertionSort/iterations:10    1520751 ns      1519390 ns           10
HeapSort/iterations:10          314176 ns       314310 ns           10
IntroSort/iterations:10        1651815 ns      1652020 ns           10
MergeSort/iterations:10         404244 ns       404650 ns           10
QuickSort/iterations:10          99242 ns        99270 ns           10
TimSort/iterations:10           227186 ns       227800 ns           10
```
#### Performance @ 10000 Elements
```
----------------------------------------------------------------------
Benchmark                            Time             CPU   Iterations
----------------------------------------------------------------------
InsertionSort/iterations:10  143194310 ns    143172560 ns           10
HeapSort/iterations:10         4019202 ns      4019850 ns           10
IntroSort/iterations:10       23762079 ns     23760950 ns           10
MergeSort/iterations:10        4211131 ns      4211410 ns           10
QuickSort/iterations:10        1311022 ns      1311410 ns           10
TimSort/iterations:10          2062253 ns      2061730 ns           10
```
#### Performance @ 100000 Elements
```
----------------------------------------------------------------------
Benchmark                            Time             CPU   Iterations
----------------------------------------------------------------------
InsertionSort/iterations:10 1.4744e+10 ns   1.4743e+10 ns           10
HeapSort/iterations:10        49430541 ns     49426390 ns           10
IntroSort/iterations:10      382370721 ns    382341380 ns           10
MergeSort/iterations:10       48949044 ns     48946050 ns           10
QuickSort/iterations:10       22748717 ns     22747290 ns           10
TimSort/iterations:10         26661064 ns     26658800 ns           10
```

### Sorted Distribution
Description: Generates a list of integers in a strictly ascending or descending order. This distribution tests the algorithm's performance on already sorted or inversely sorted data, which can be best-case or worst-case scenarios for some algorithms.

![sorted dist](./data/images/image-1.png)
#### Performance @ 100 Elements
```
----------------------------------------------------------------------
Benchmark                            Time             CPU   Iterations
----------------------------------------------------------------------
InsertionSort/iterations:10        889 ns          770 ns           10
HeapSort/iterations:10           21842 ns        21850 ns           10
IntroSort/iterations:10          32129 ns        32250 ns           10
MergeSort/iterations:10          39007 ns        39180 ns           10
QuickSort/iterations:10          20311 ns        20330 ns           10
TimSort/iterations:10             4318 ns         4300 ns           10
```
#### Performance @ 1000 Elements
```
----------------------------------------------------------------------
Benchmark                            Time             CPU   Iterations
----------------------------------------------------------------------
InsertionSort/iterations:10       4755 ns         4640 ns           10
HeapSort/iterations:10          253002 ns       253050 ns           10
IntroSort/iterations:10         272031 ns       272050 ns           10
MergeSort/iterations:10         396062 ns       396380 ns           10
QuickSort/iterations:10         956427 ns       956590 ns           10
TimSort/iterations:10            47588 ns        47590 ns           10
```
#### Performance @ 10000 Elements
```
----------------------------------------------------------------------
Benchmark                            Time             CPU   Iterations
----------------------------------------------------------------------
InsertionSort/iterations:10      48698 ns        48600 ns           10
HeapSort/iterations:10         3588422 ns      3587710 ns           10
IntroSort/iterations:10        4090156 ns      4088530 ns           10
MergeSort/iterations:10        3642071 ns      3642550 ns           10
QuickSort/iterations:10      104308745 ns    104296670 ns           10
TimSort/iterations:10           952276 ns       952140 ns           10
```
#### Performance @ 100000 Elements
```
----------------------------------------------------------------------
Benchmark                            Time             CPU   Iterations
----------------------------------------------------------------------
InsertionSort/iterations:10     649226 ns       649540 ns           10
HeapSort/iterations:10        40015274 ns     40010090 ns           10
IntroSort/iterations:10       45798785 ns     45796140 ns           10
MergeSort/iterations:10       37868775 ns     37867300 ns           10
QuickSort/iterations:10     1.0498e+10 ns   1.0497e+10 ns           10
TimSort/iterations:10         13667723 ns     13667140 ns           10
```
### Slightly Scrambled

Description: Starts with a sorted list and introduces a small percentage of randomness by swapping a specified percentage of its elements. It simulates scenarios where the data is nearly sorted but has minor deviations.

![slight scrambled dist](./data/images/image-3.png)
#### Performance @ 100 Elements
```
----------------------------------------------------------------------
Benchmark                            Time             CPU   Iterations
----------------------------------------------------------------------
InsertionSort/iterations:10       4650 ns         4510 ns           10
HeapSort/iterations:10           25809 ns        25830 ns           10
IntroSort/iterations:10          41191 ns        41190 ns           10
MergeSort/iterations:10          33926 ns        33920 ns           10
QuickSort/iterations:10           7131 ns         7110 ns           10
TimSort/iterations:10             7229 ns         7250 ns           10
```
#### Performance @ 1000 Elements
```
----------------------------------------------------------------------
Benchmark                            Time             CPU   Iterations
----------------------------------------------------------------------
InsertionSort/iterations:10     298483 ns       299000 ns           10
HeapSort/iterations:10          353367 ns       353580 ns           10
IntroSort/iterations:10         617746 ns       618350 ns           10
MergeSort/iterations:10         355833 ns       356420 ns           10
QuickSort/iterations:10         162069 ns       162220 ns           10
TimSort/iterations:10           114440 ns       114560 ns           10
```
#### Performance @ 10000 Elements
```
----------------------------------------------------------------------
Benchmark                            Time             CPU   Iterations
----------------------------------------------------------------------
InsertionSort/iterations:10   17944902 ns     17944230 ns           10
HeapSort/iterations:10         3659975 ns      3660190 ns           10
IntroSort/iterations:10        7593853 ns      7594060 ns           10
MergeSort/iterations:10        3859926 ns      3860220 ns           10
QuickSort/iterations:10        2818310 ns      2818520 ns           10
TimSort/iterations:10          1292200 ns      1292590 ns           10
```

#### Performance @ 100000 Elements
```
----------------------------------------------------------------------
Benchmark                            Time             CPU   Iterations
----------------------------------------------------------------------
InsertionSort/iterations:10 1751252432 ns   1751247350 ns           10
HeapSort/iterations:10        41077500 ns     41077760 ns           10
IntroSort/iterations:10      138943535 ns    138943800 ns           10
MergeSort/iterations:10       41819531 ns     41819870 ns           10
QuickSort/iterations:10       31056510 ns     31056870 ns           10
TimSort/iterations:10         14895201 ns     14895630 ns           10
```

### Sorted Blocks
Description: Creates multiple sorted blocks of a specified size, then shuffles these blocks. This distribution checks how sorting algorithms manage partially ordered data, where local order exists, but the overall sequence is unordered.

![sorted block dist](./data/images/image-4.png)

#### Performance @ 100 Elements
```
----------------------------------------------------------------------
Benchmark                            Time             CPU   Iterations
----------------------------------------------------------------------
InsertionSort/iterations:10      25915 ns        25840 ns           10
HeapSort/iterations:10           27475 ns        27490 ns           10
IntroSort/iterations:10          55319 ns        55360 ns           10
MergeSort/iterations:10          35254 ns        35260 ns           10
QuickSort/iterations:10           8611 ns         8600 ns           10
TimSort/iterations:10             8009 ns         8010 ns           10
```
#### Performance @ 1000 Elements
```
----------------------------------------------------------------------
Benchmark                            Time             CPU   Iterations
----------------------------------------------------------------------
InsertionSort/iterations:10    1301353 ns      1301530 ns           10
HeapSort/iterations:10          248110 ns       248090 ns           10
IntroSort/iterations:10        1161177 ns      1161840 ns           10
MergeSort/iterations:10         309553 ns       309560 ns           10
QuickSort/iterations:10         183370 ns       183370 ns           10
TimSort/iterations:10           157671 ns       157780 ns           10
```
#### Performance @ 10000 Elements
```
----------------------------------------------------------------------
Benchmark                            Time             CPU   Iterations
----------------------------------------------------------------------
InsertionSort/iterations:10  143626983 ns    143623430 ns           10
HeapSort/iterations:10         3958272 ns      3958510 ns           10
IntroSort/iterations:10       17874126 ns     17874440 ns           10
MergeSort/iterations:10        3858435 ns      3858150 ns           10
QuickSort/iterations:10        2792754 ns      2793000 ns           10
TimSort/iterations:10          1532463 ns      1533100 ns           10
```
#### Performance @ 100000 Elements
```
----------------------------------------------------------------------
Benchmark                            Time             CPU   Iterations
----------------------------------------------------------------------
InsertionSort/iterations:10 1.4946e+10 ns   1.4946e+10 ns           10
HeapSort/iterations:10        47151479 ns     47151740 ns           10
IntroSort/iterations:10      242865661 ns    242866220 ns           10
MergeSort/iterations:10       49465511 ns     49465740 ns           10
QuickSort/iterations:10       65935750 ns     65933040 ns           10
TimSort/iterations:10         26468712 ns     26469230 ns           10
```

### Single Big Swap
Description: Divides the list into two halves and swaps their positions. This method is useful for understanding how algorithms deal with large, contiguous segments of data that are out of place.

![single big swap dist](./data/images/image-5.png)
#### Performance @ 100 Elements
```
----------------------------------------------------------------------
Benchmark                            Time             CPU   Iterations
----------------------------------------------------------------------
InsertionSort/iterations:10      20408 ns        20320 ns           10
HeapSort/iterations:10           38961 ns        39030 ns           10
IntroSort/iterations:10          76671 ns        76780 ns           10
MergeSort/iterations:10          44721 ns        44700 ns           10
QuickSort/iterations:10          27048 ns        27000 ns           10
TimSort/iterations:10             6120 ns         6110 ns           10
```
#### Performance @ 1000 Elements
```
----------------------------------------------------------------------
Benchmark                            Time             CPU   Iterations
----------------------------------------------------------------------
InsertionSort/iterations:10    1476387 ns      1477140 ns           10
HeapSort/iterations:10          426505 ns       426720 ns           10
IntroSort/iterations:10         660126 ns       660570 ns           10
MergeSort/iterations:10         342105 ns       342210 ns           10
QuickSort/iterations:10        1266538 ns      1266910 ns           10
TimSort/iterations:10            76403 ns        76380 ns           10
```
#### Performance @ 10000 Elements
```
----------------------------------------------------------------------
Benchmark                            Time             CPU   Iterations
----------------------------------------------------------------------
InsertionSort/iterations:10  151600721 ns    151598710 ns           10
HeapSort/iterations:10         4088013 ns      4088280 ns           10
IntroSort/iterations:10        8217605 ns      8217910 ns           10
MergeSort/iterations:10        3872923 ns      3872600 ns           10
QuickSort/iterations:10      131313102 ns    131312610 ns           10
TimSort/iterations:10           892437 ns       892760 ns           10
```
#### Performance @ 100000 Elements
```
----------------------------------------------------------------------
Benchmark                            Time             CPU   Iterations
----------------------------------------------------------------------
InsertionSort/iterations:10 1.5359e+10 ns   1.5359e+10 ns           10
HeapSort/iterations:10        45066567 ns     45067110 ns           10
IntroSort/iterations:10      109166606 ns    109167000 ns           10
MergeSort/iterations:10       45069455 ns     45069770 ns           10
QuickSort/iterations:10     1.1791e+10 ns   1.1791e+10 ns           10
TimSort/iterations:10         15074878 ns     15075120 ns           10
```

### Reversed Distribution
Description: Generates a list where the elements are in completely reverse order. This can be particularly challenging for some algorithms and is often considered a worst-case scenario.

![reversed dist](./data/images/image-6.png)

#### Performance @ 100 Elements
```
----------------------------------------------------------------------
Benchmark                            Time             CPU   Iterations
----------------------------------------------------------------------
InsertionSort/iterations:10      28579 ns        28350 ns           10
HeapSort/iterations:10           24300 ns        24300 ns           10
IntroSort/iterations:10          36117 ns        36180 ns           10
MergeSort/iterations:10          28496 ns        28540 ns           10
QuickSort/iterations:10          26650 ns        26670 ns           10
TimSort/iterations:10            16660 ns        16660 ns           10
```
#### Performance @ 1000 Elements
```
----------------------------------------------------------------------
Benchmark                            Time             CPU   Iterations
----------------------------------------------------------------------
InsertionSort/iterations:10    3104439 ns      3103110 ns           10
HeapSort/iterations:10          330753 ns       330240 ns           10
IntroSort/iterations:10         377125 ns       377560 ns           10
MergeSort/iterations:10         385375 ns       385560 ns           10
QuickSort/iterations:10        2488227 ns      2488620 ns           10
TimSort/iterations:10           260315 ns       260330 ns           10
```
#### Performance @ 10000 Elements
```
----------------------------------------------------------------------
Benchmark                            Time             CPU   Iterations
----------------------------------------------------------------------
InsertionSort/iterations:10  277590811 ns    277564000 ns           10
HeapSort/iterations:10         4133870 ns      4134110 ns           10
IntroSort/iterations:10        4552915 ns      4552380 ns           10
MergeSort/iterations:10        3643185 ns      3643580 ns           10
QuickSort/iterations:10      245551136 ns    245531990 ns           10
TimSort/iterations:10          1654472 ns      1654670 ns           10
```
#### Performance @ 100000 Elements
```
----------------------------------------------------------------------
Benchmark                            Time             CPU   Iterations
----------------------------------------------------------------------
InsertionSort/iterations:10 2.8843e+10 ns   2.8843e+10 ns           10
HeapSort/iterations:10        44387239 ns     44387670 ns           10
IntroSort/iterations:10       57096251 ns     57096830 ns           10
MergeSort/iterations:10       43619281 ns     43619510 ns           10
QuickSort/iterations:10     2.5798e+10 ns   2.5798e+10 ns           10
TimSort/iterations:10         29026630 ns     29026940 ns           10
```
### Few Unique Distribution
Description: Generates a list with a few unique values, repeated multiple times. This distribution tests how sorting algorithms perform when dealing with high-frequency, low-diversity data sets.

![few unique dist](./data/images/image-7.png)

#### Performance @ 100 Elements
```
----------------------------------------------------------------------
Benchmark                            Time             CPU   Iterations
----------------------------------------------------------------------
InsertionSort/iterations:10      11159 ns        11050 ns           10
HeapSort/iterations:10           17529 ns        17500 ns           10
IntroSort/iterations:10          40391 ns        40390 ns           10
MergeSort/iterations:10          23736 ns        23720 ns           10
QuickSort/iterations:10           5170 ns         5160 ns           10
TimSort/iterations:10            10834 ns        10850 ns           10
```
#### Performance @ 1000 Elements
```
----------------------------------------------------------------------
Benchmark                            Time             CPU   Iterations
----------------------------------------------------------------------
InsertionSort/iterations:10     949453 ns       949670 ns           10
HeapSort/iterations:10          324300 ns       324170 ns           10
IntroSort/iterations:10         582509 ns       583050 ns           10
MergeSort/iterations:10         336418 ns       336610 ns           10
QuickSort/iterations:10         232397 ns       232430 ns           10
TimSort/iterations:10           166233 ns       166370 ns           10
```
#### Performance @ 10000 Elements
```
----------------------------------------------------------------------
Benchmark                            Time             CPU   Iterations
----------------------------------------------------------------------
InsertionSort/iterations:10  117472961 ns    117469890 ns           10
HeapSort/iterations:10         3481791 ns      3482280 ns           10
IntroSort/iterations:10        7306880 ns      7307140 ns           10
MergeSort/iterations:10        4190845 ns      4191210 ns           10
QuickSort/iterations:10       24502024 ns     24502500 ns           10
TimSort/iterations:10          2108057 ns      2109440 ns           10
```
#### Performance @ 100000 Elements
```
----------------------------------------------------------------------
Benchmark                            Time             CPU   Iterations
----------------------------------------------------------------------
InsertionSort/iterations:10 1.1755e+10 ns   1.1755e+10 ns           10
HeapSort/iterations:10        41744962 ns     41745610 ns           10
IntroSort/iterations:10      123699261 ns    123699490 ns           10
MergeSort/iterations:10       44126545 ns     44124430 ns           10
QuickSort/iterations:10     2016892575 ns   2016888130 ns           10
TimSort/iterations:10         21675800 ns     21676060 ns           10
----------------------------------------
```