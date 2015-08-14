/*
copyright xu(xusiwei1236@163.com), all right reserved.

Median of Two Sorted Arrays
==============================

There are two sorted arrays nums1 and nums2 of size m and n respectively. Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).
*/

#include <algorithm>
#include <stdio.h>

#ifdef DEBUG
#define trace printf
#else
#define trace
#endif

// [low, high], post condition: A[low, ret] <= key
int binarySearch(int A[], int low, int high, int key)
{
    while(low <= high) {
        int mid = low + (high - low) / 2;
        if(A[mid] == key) {
            return mid;
        }
        else if( A[mid] < key) {
            low = mid+1;
        }
        else { // A[mid] > key
            high = mid-1;
        }
    }
    return low;
}

double findMedianSortedArraysRecusive(int A[], int m, int B[], int n, int lowA, int highA, int lowB, int highB)
{
    // suppose that A[] longer than B[],
    int mid = lowA + (highA - lowA) / 2;
    int pos = binarySearch(B, lowB, highB, A[mid]);
    int num = mid + pos;
    // [A0, A1, A2, ... ..., Amid, ... ..., Am-1, Am]
    // [B0, B1, B2, ..., Bpos, ... ... ..., Bn-1, Bn]
    //  so,
    //     [A0, A1, ..., Amid-1] U [B0, B1, ..., Bpos-1]
    // <= Amid <=
    //     [Amid+1, ..., Am] U [Bpos, ..., Bn]
    
    trace("\n%s %p: %d, %p:%d,  %d, %d, %d, %d)\n", __FUNCTION__, A, m, B, n, lowA, highA, lowB, highB);
    trace("mid: %d, A[mid]: %d, pos: %d, B[pos]: %d, num: %d\n", mid, A[mid], pos, B[pos], num);

    if(num == (m+n)/2) {
        if((m+n) % 2 == 1) { // odd total length.
            return A[mid];
        }
        else {
            int less = A[mid];
            // for even total length
            if(pos > 0 && mid > 0) {
                less = A[mid-1] > B[pos-1] ? A[mid-1] : B[pos-1]; // get the bigger the near.
            }
            else if(mid > 0) {
                less = A[mid-1];
            }
            else if(pos > 0) {
                less = B[pos-1];
            }
            trace("## %d + %d, %d\n", less, A[mid], num);
            return (less + A[mid]) / 2.0;
        }
    }
    else if(num < (m+n)/2) {
        lowA = mid+1;
        lowB = pos;
        if(highA - lowA > highB - lowB)
            return findMedianSortedArraysRecusive(A, m, B, n, lowA, highA, lowB, highB);
        return findMedianSortedArraysRecusive(B, n, A, m, lowB, highB, lowA, highA);
    }
    else { // if(num > (m+n)/2)
        highA = mid-1;
        highB = pos-1;
        if(highA - lowA > highB - lowB)
            return findMedianSortedArraysRecusive(A, m, B, n, lowA, highA, lowB, highB);
        return findMedianSortedArraysRecusive(B, n, A, m, lowB, highB, lowA, highA);
    }
}

double findMedianSortedArrays(int A[], int m, int B[], int n)
{
    if(m == 0 && n == 0) return 0.0;
    
    if(m == 0) return n%2 ? B[n/2] : (B[n/2-1] + B[n/2])/2.0;
    if(n == 0) return m%2 ? A[m/2] : (A[m/2-1] + A[m/2])/2.0;
    
    if(m > n)
        return findMedianSortedArraysRecusive(A, m, B, n, 0, m-1, 0, n-1);
    return findMedianSortedArraysRecusive(B, n, A, m, 0, n-1, 0, m-1);
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////

#define ARRAYSIZE(a) sizeof(a)/sizeof(a[0])
int main()
{
    int A[] = {
    115,201,509,700,738,895,1024,1047,1248,1264,1272,1453,1492,1540,1552,1590,1611,1692,1703,1769,1911,1952,1966,2021,2144,2357,2374,2458,2474,2499,2502,2540,2735,2805,2921,2944,3175,3194,3438,3475,3808,3862,3899,4084,4161,4268,4480,4528,4592,4645,4725,4774,4872,4987,5100,5184,5358,5377,5460,5561,5569,5580,5750,5779,5805,5971,6019,6085,6135,6153,6210,6377,6472,6612,6631,6640,6664,6871,6929,6957,7092,7158,7190,7297,7396,7551,7594,7854,7929,7933,8051,8311,8337,8358,8376,8391,8406,8421,8551,8563,8579,8594,8609,8749,8889,8957,9000,9013,9046,9117,9148,9251,9336,9532,9624,9891,9916,10027,10057,10063,10217,10236,10279,10626,10711,10809,10883,11108,11176,11190,11340,11383,11513,11584,11669,11693,11880,11984,12029,12052,12054,12080,12149,12247,12297,12326,12400,12453,12463,12736,12851,12963,12999,13185,13233,13287,13552,13605,13686,13701,13718,13725,13959,14001,14132,14409,14432,14440,14537,14622,14701,14756,14839,14853,14983,15063,15117,15283,15370,15588,15909,16157,16259,16418,16448,16641,16653,16671,16710,16895,16915,16990,16995,17019,17109,17171,17181,17250,17513,17568,17620,17672,17722,17827,17936,18007,18037,18064,18081,18222,18695,18784,18957,19048,19116,19117,19127,19198,19304,19309,19387,19516,19572,19642,19788,19900,19922,20000,20046,20186,20726,20776,20920,20998,21200,21207,21213,21225,21431,21434,21543,21578,21591,21602,21648,21700,21785,21840,22014,22017,22036,22078,22136,22247,22250,22361,22438,22483,22493,22540,22674,22696,22746,22751,22801,22913,22919,22941,22991,23114,23160,23210,23274,23356,23427,23642,23712,23781,23794,23799,23804,23824,23931,24003,24218,24236,24449,24455,24498,24610,24670,24681,24873,24879,24964,25026,25076,25095,25148,25171,25198,25259,25276,25283,25661,25870,25883,25929,26068,26113,26152,26212,26356,26374,26630,26710,26724,26985,27087,27090,27109,27275,27285,27338,27353,27518,27618,27684,27822,27879,27981,28031,28056,28099,28147,28229,28266,28285,28386,28412,28464,28643,28678,28718,28735,28848,28936,29170,29175,29220,29251,29386,29405,29496,29562,29654,29711,29895,30086,30116,30168,30193,30212,30231,30244,30368,30408,30558,30722,30779,30790,30806,30817,30900,30919,31090,31106,31293,31357,31373,31632,31676,31744,31797,31903,32149,32209,32392,32539,32620,32644,32744
        // 1, 3, 5, 7, 7, 7, 9,  11,  15, 17, 19
        // 1, 3, 5, 7, 9
        // 1, 1
    };    
    int B[] = { 
    10,269,374,413,440,612,652,864,876,1070,1110,1439,1683,2010,2024,2087,2136,2285,2705,3018,3112,3279,3412,3521,3644,3664,3760,3860,3927,4022,4374,4408,4520,4580,4864,5014,5195,5200,5473,5481,5767,5874,6382,6390,6472,6480,6548,6562,6624,7021,7062,7086,7089,7190,7256,7551,7954,8180,8249,8264,8367,8399,8407,8429,8652,8700,8738,9074,9136,9214,9874,10008,10028,10060,10225,10237,10334,10354,10464,10879,11096,11188,11483,11619,11632,11698,11810,11820,11871,11946,12281,12434,12464,12600,12954,13075,13163,13360,13365,13429,13654,13679,13818,14029,14067,14188,14343,14436,14502,14575,14582,14750,14774,14868,15056,15514,15581,15648,16072,16299,16348,16499,16576,16596,16752,16795,17106,17163,17206,17647,17716,17958,18132,18664,18756,18766,18938,18962,19062,19097,19115,19232,19336,19341,19412,19558,19661,19683,19872,20134,20215,20245,20476,20958,20968,21040,21097,21100,21180,21221,21313,21410,21456,21613,21649,21651,21708,21938,22160,22244,22249,22286,22304,22378,22412,22572,22580,22681,22890,22987,23185,23593,23654,24014,24457,24952,25009,25128,25178,25349,25397,25430,25435,26134,26215,26251,26263,26307,26391,26507,26613,27053,27059,27075,27114,27139,27201,27325,27371,27610,27700,28025,28157,28568,28609,28665,28681,28866,28987,29466,29521,29600,29664,29794,29901,30118,30145,30263,30364,30516,30922,30983,31371,31448,31507,31687,32115,32130,32308,32643
        // 2, 4, 8, 20, 21, 22, 23, 24 
        // 2, 4, 6, 8, 10
        // 1, 2
    };
    
    int m = ARRAYSIZE(A);
    int n = ARRAYSIZE(B);
    
    int dst = rand() % m;
    int pos = binarySearch(A, 0, m-1, A[dst]);
    printf("\nkey: %d, dst: %d, pos: %d\n", A[dst], dst, pos);
    
    int t = m + n;
    int *C = new int[t];
    std::merge(A, A+m, B, B+n, C);
    
    std::sort(C, C + t);
    
    if(t%2) printf("Median: %f at {%d}\n", C[t/2], t/2);
    else printf("Median: %f at {%d: %d, %d: %d}\n", (C[t/2-1] + C[t/2])/2.0, t/2-1, C[t/2-1], t/2, C[t/2]);

    printf("Median: %f\n", findMedianSortedArrays(A, m, B, n));
    
    return 0;
}

