#include <iostream>
#include <vector>
#include <map>
#include "context.h"

using namespace std;

int main() {
    vector<Context<int>> op;
    Context<int> scalar(5);
    map<string, Context<int>> mp;
    mp.insert({"key", scalar});
    mp["k"] = scalar;
    op.push_back(scalar);
    Context<map<string, Context<int>>> map_container(mp);
    cout << map_container["k"].GetScalar() << endl;
    Context<vector<Context<int>>> vector_context(op);
    cout << vector_context[0].GetScalar() << endl;
    cout << scalar.ObjectType() << endl;
    cout << map_container.ObjectType() << endl;
    cout << vector_context.ObjectType() << endl;
    Context<map<string, Context<int>>> map_c;
    map_c = map_container;
    cout << map_c["k"].GetScalar() << endl;
    map_c.Delete();
}
