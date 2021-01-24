#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include "Jeans.h"
#include "Collection.h"

using CollectionJN  = Collection<Jeans, Jeans_colors, Jeans_sizes>;

istream& operator>>(istream& is, CollectionJN& c) {

    string jcols;

    string jsize;

    Jeans_colors jColors;
    
    Jeans_sizes jSizes;
    
    while (is>>jcols>>jsize) { // input stream for different colors and sizes

        if (jcols == "white")
            jColors = Jeans_colors::white;
        if (jcols == "black")
            jColors = Jeans_colors::black;
        if (jcols == "blue")
            jColors = Jeans_colors::blue;
        if (jcols == "grey")
            jColors = Jeans_colors::grey;
        if (jsize == "small") 
            jSizes = Jeans_sizes::small;
        if (jsize == "medium") 
            jSizes = Jeans_sizes::medium;
        if (jsize == "large") 
            jSizes = Jeans_sizes::large;
        if (jsize == "xlarge")
            jSizes = Jeans_sizes::xlarge;

        Jeans * sb1 = new Jeans(jColors, jSizes);
        c.insert_item(*sb1);
    }
    return is;
}

void test_jeans(){
        Jeans jeans_1 = Jeans(Jeans_colors::grey, Jeans_sizes::small);
        Jeans jeans_2 = Jeans(Jeans_colors::grey, Jeans_sizes::large);
        Jeans jeans_3 = Jeans(Jeans_colors::blue, Jeans_sizes::large);
        Jeans jeans_4 = Jeans(Jeans_colors::black, Jeans_sizes::medium);
        CollectionJN collection_0;
        CollectionJN collection_1;
        CollectionJN collection_2(3);
        CollectionJN collection_3(5);
        CollectionJN collection_file(1);
        collection_0.insert_item(jeans_1);
        collection_0.make_empty();
        collection_1.insert_item(jeans_1);
        collection_2.insert_item(jeans_2);
        
        collection_2.print_items();
        collection_2.insert_item(Jeans(Jeans_colors::blue, Jeans_sizes::small));
        collection_2.insert_item(jeans_3);
        collection_2.insert_item(jeans_3);
        CollectionJN collection_copy(collection_1);
        collection_1.insert_item(Jeans(Jeans_colors::black, Jeans_sizes::small));
        CollectionJN collection_7 = move(collection_1);
        collection_2.insert_item(Jeans(Jeans_colors::blue, Jeans_sizes::medium));
        collection_2.insert_item(Jeans(Jeans_colors::grey, Jeans_sizes::large));
        collection_2.insert_item(Jeans(Jeans_colors::grey, Jeans_sizes::large));
        collection_2.remove_this_item(jeans_2);
        
        collection_2.print_items();
        collection_copy.make_empty();
        if(collection_2.is_empty()){
            collection_2.insert_item(Jeans(Jeans_colors::black, Jeans_sizes::small));
        }
        ifstream ifs("jeans1.data");
        ifs >> collection_file;
        collection_file.insert_item(jeans_3);
        collection_file.insert_item(jeans_3);
        collection_2.insert_item(jeans_3);
        collection_2.insert_item(jeans_3);
        collection_2.insert_item(jeans_2);
        collection_2.insert_item(jeans_1);
        
        collection_file.print_items();
      
                    swap(collection_file,collection_2);
                    collection_3 = make_union(collection_file,collection_2);                
                     if((collection_3.total_items() - collection_2.total_items()) == collection_file.total_items()){
                          sort_by_size(collection_2,Sort_choice::selection_sort);
                          cout<<collection_3;
                     }
}
