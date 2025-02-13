use std::collections::HashSet;
fn main() {
    let edges = vec!["Node1, Node3", "A, B", "B, C", "A, D", "Node3, A"];

    let mut nodes = HashSet::new();
    let mut children = HashSet::new();

    for edge in edges {
        // return type is a vector of borrowed string slices
        let parts: Vec<&str> = edge.split(",").map(|s| s.trim()).collect();
        /*
        return type is a vector of newly created strings
        let parts: Vec<String> = edge.split(",").map(|s| s.trim().to_string()).collect();
         */
        if parts.len() != 2 {
            continue;
        } // raise an error & exit?
        let parent = parts[0].to_string();
        let child = parts[1].to_string();

        nodes.insert(parent.clone());
        children.insert(child.clone());
    }

    // find the nodes that are not children
    let nodes_not_children: HashSet<_> = nodes.difference(&children).collect();

    // assert equal to 1
    assert!(
        nodes_not_children.len() == 1,
        "There should only be 1 root node"
    );
    for node in nodes_not_children {
        println!("Root node {}", node)
    }
}
