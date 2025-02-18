#include <iostream>


int max_area(const std::vector<int>& heights){

    if(heights.size() <= 1){ return 0; }
    std::vector<int>::const_iterator p1 = heights.begin();
    std::vector<int>::const_iterator p2 = --(heights.end());


    int max_area = -1; 
    while(p1 < p2){
        int height = std::min(*p1, *p2);
        int width = (p2 - heights.begin()) - (p1 - heights.begin());
        int area = height * width; 
        std::cout << "height = " << height << " and " 
                <<  " width = " << width << " area = " 
                << area << std::endl
                ; 
        max_area = std::max(area, max_area); 
        // move the pointers. 
        if (*p1 < *p2){ ++p1;} else { --p2;}
    }

    return max_area; 

}

int main(int argc, char * argv[]){
    std::cout << "starting" << std::endl; 
    //const std::vector<int> graph_heights = {7,1,2,3,9};
    const std::vector<int> graph_heights = {1, 8, 6, 2, 5, 4, 8, 3, 7}; 
    int result = max_area(graph_heights);
    std::cout << "Max area -> " << result << std::endl;
    return 0; 
}