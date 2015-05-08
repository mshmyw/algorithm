#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void findPermutations(vector<int> &num, vector<bool> &used, vector<int> &per, vector<vector<int> > &allPer) {
    if(per.size()==num.size()) {
        allPer.push_back(per);
        return;
    }

    for(int i=0; i < num.size(); i++) {
        if(used[i] || ((i != 0) && (num[i - 1] == num[i]) && used[i - 1])) continue;
        used[i] = true; //visited flag
        per.push_back(num[i]); //save
        findPermutations(num, used, per, allPer);
        used[i] = false;
        per.pop_back();
    }

}

vector<vector<int> > permute(vector<int> &num) {
    vector<vector<int> > allPer;
    if(num.empty()) return allPer;
    vector<bool> used(num.size(), false);
    vector<int> per;
    findPermutations(num, used, per, allPer);

    return allPer;
}

void print_iterator(vector< vector<int> > result){
    vector< vector<int> >::iterator it;
    vector<int>::iterator it_inner;

    for(it = result.begin(); it != result.end(); it++){
        for(it_inner = (*it).begin(); it_inner != (*it).end(); it_inner++)
            cout<<*it_inner;
        cout<<endl;
    }

}
int main(void){
    int array[] = {1, 2, 3};
    int n = sizeof(array) / sizeof(array[0]);
    vector<int> num(array, array + n);
    vector< vector<int> > result;
   result =  permute(num);

   print_iterator(result);

    return 0;
}
