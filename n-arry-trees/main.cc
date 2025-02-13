#include <iostream>
#include <string>
#include <set>
#include <cassert>
/*
Input: ["Node1, Node3", "A, B", "B, C", "A, D", "Node3, A"] 
Restructure the tree, and return the root.
*/


/*
An n-arry tree, the root is the node that is NOT a child
*/
/*
1 -> Parse the input: Each string "Parent, child" reprensents a directed edge in a graph
2 -> Identity all unique nodes
3 -> Track all child nodes (Any node that appears as a child is not the root)
4 -> The node that never appears as a child is the root 
*/

/*
Probably worth asking about things like max number of nodes, length of node names
Maybe have a think about runtime of set_difference (personally, I like using the stl for this but interviews are weird.)
And for bonus points, a few test cases! Like some muppet has a tree input with 2 nodes as the root! Or names a node twice
*/

int main(int argc, char* argv[]){
    std::cout << "starting" << std::endl; 

    // item 1 is the name, item2 is the child
    std::set<std::string> node_names; 
    std::multiset<std::string> node_children; 

    std::vector<std::string> edges ={ "Node1, Node3", "A, B", "B, C", "A, D", "Node3, A"};

    for(std::vector<std::string>::const_iterator i = edges.begin();
        i != edges.end(); 
        ++i
    ){
        std::string::size_type found = i->find_first_of(",");
        std::string parent = i->substr(0,found); 
        std::string child = i->substr(found+1); 
        std::string::iterator pos = std::remove_if(parent.begin(), parent.end(), isspace);
        if(pos != parent.end())
            parent.erase(pos, parent.end());
        pos = std::remove_if(child.begin(), child.end(), isspace);
        if(pos != child.end())
            child.erase(pos, child.end());
        std::cout << "parent -> " << parent << "\tchild -> " << child << std::endl;
        node_names.insert(parent); 
        node_children.insert(child); 

    }
    // std::set_difference to find elements in 'nodes' but not in 'children'
    std::set<std::string> nodes_not_children;
    std::set_difference(node_names.begin(), node_names.end(), node_children.begin(), node_children.end(), 
                            std::inserter(nodes_not_children, nodes_not_children.begin())); 

    // should only be 1 entry
    assert(nodes_not_children.size() == 1); 
    for(
        std::set<std::string>::const_iterator iter = nodes_not_children.begin(); 
        iter != nodes_not_children.end(); 
        ++ iter){
            std::cout << "Nodes not children " << *iter << std::endl; 

    }

    return 0; 
} 