#include<bits/stdc++.h>

using namespace std;

int ternary_search(vector<int> a, int beg, int en, int x){
    if(beg == en){                  // if the size of current segment of array is one
        if(x == a[beg]){
            return beg;             // if required element present, return its position
        }
        return -1;                  // element not present in the segment
    }
    int mid1 = beg + (en-beg)/3;      // mid1 and mid2 divides segment beg<->en into three equal subsegments,
    int mid2 = en - (en-beg)/3;       // beg<->mid1, mid1<->mid2 and mid2<->en
    if(beg <= en){
        if(a[mid1] == x){               // element found at mid1
            return mid1;
        }
        if(a[mid2] == x){               // element found at mid2
            return mid2;
        }
        if(x < a[mid1]){                      // if the element is smaller than element present at mid1
            return ternary_search(a,beg,mid1-1,x);    // discard subsegment mid1<->en and call for segement beg<->mid1-1
        }
        if(x > a[mid2]){                      // if the element is bigger than element present at mid2
            return ternary_search(a,mid2+1,en,x);      // discard subsegment beg<->mid2 and call for segement mid2+1<->en
        }
        return ternary_search(a,mid1+1,mid2-1,x);     // else call for the middle segement i.e., mid1+1<->mid2-1
    }
    return -1;                              // element not fount in current segment beg<->en
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;                          // number of elements in array
    cin>>n;
    vector<int> a(n, 0);
    for(int i=0;i<n;i++){
        cin>>a[i];                  // array must be sorted to use ternary search
    }
    int val;
    cin>>val;
    int pos = ternary_search(a,0,n-1,val);
    cout<<pos;      // the index of element val in array a (-1 if not present)
    return 0;
}
