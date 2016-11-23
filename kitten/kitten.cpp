#include <iostream>
#include <sstream>
#include <string>

#include <map>
#include <list>

typedef std::map< int, std::list<int> > _t_tree;

std::string depth_first_search(_t_tree tree, int this_node, int seeking_for_node) {
	if (this_node == seeking_for_node) {
		return std::to_string(seeking_for_node);
	}

	if (tree.count(this_node) > 0) {
		for (std::list<int>::iterator it = tree[this_node].begin(); it != tree[this_node].end(); it++) {
			if (*it == this_node) {
				continue;
			}

			std::string part = depth_first_search(tree, *it, seeking_for_node);
			if (part != "") {
				return part + " " + std::to_string(this_node);
			}
		}
	}

	return "";
}

int main(void) {
	std::string str;

	// Get number of the node the kitten sits on
	std::getline(std::cin, str); 
	std::stringstream stream(str);
	int kitten_node;
	stream >> kitten_node;

	// Read tree structure
	_t_tree tree;
	std::getline(std::cin, str);
	while (str != "-1") {
		std::stringstream stream(str);

		int node;
		stream >> node;

		std::list<int> descendants;
		int new_descendant;
		while (stream >> new_descendant) {
			descendants.push_back( new_descendant );
		}
		tree.insert( make_pair( node, descendants ) );
		
		std::getline(std::cin, str);
	}

	int root;
	for (_t_tree::iterator it = tree.begin(); it != tree.end(); it++) {
		int root_candidate = it->first;
		bool still_true_root = true;
		for (_t_tree::iterator jt = tree.begin(); jt != tree.end() && still_true_root; jt++) {
			if (it == jt) {
				continue;
			}

			for (std::list<int>::iterator lt = jt->second.begin(); lt != jt->second.end(); lt++) {
				if (*lt == root_candidate) {
					still_true_root = false;
					break;
				}
			}
		}

		if (still_true_root) {
			root = root_candidate;
			break;
		}
	}

	// Find path
	std::cout << depth_first_search(tree, root, kitten_node) << std::endl;

	return 0;
}

