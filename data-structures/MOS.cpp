const int BLOCK;

struct Query {
  int l, r, idx;
  bool operator<(Query other) const{
    if(l/BLOCK != other.l / BLOCK) return l < other.l;
    return (l / BLOCK & 1) ? (r < other.r) : (r > other.r);
  }
};

// TODO
void remove(int idx){
}

// TODO
void add(int idx){
}

// TODO
int get_answer(){
}

vector<int> mo_s_algorithm(vector<Query> queries) {
    vector<int> answers(queries.size());
    sort(queries.begin(), queries.end());

    // TODO: initialize data structure

    int cur_l = 0;
    int cur_r = -1;
    // invariant: data structure will always reflect the range [cur_l, cur_r]
    for (Query q : queries) {
        while (cur_l > q.l) {
            cur_l--;
            add(cur_l);
        }
        while (cur_r < q.r) {
            cur_r++;
            add(cur_r);
        }
        while (cur_l < q.l) {
            remove(cur_l);
            cur_l++;
        }
        while (cur_r > q.r) {
            remove(cur_r);
            cur_r--;
        }
        answers[q.idx] = get_answer();
    }
    return answers;
}
