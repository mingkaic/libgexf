/* 
 * File:   NodeIter.cpp
 * Author: sebastien
 * 
 * Created on 9 juillet 2009, 15:48
 */

#include "nodeiter.h"

using namespace std;

namespace libgexf {

NodeIter::NodeIter(const Graph* g): _graph(g), _cpt(0), _nb_items(g->getNodeCount()) {
    this->begin();
}

NodeIter::~NodeIter() {
}

NodeIter* NodeIter::begin() {
    _it = _graph->_nodes.begin();
    return this;
}

bool NodeIter::hasNext() const {
    return _nb_items != 0 && _cpt != _nb_items;
}

t_id NodeIter::next() {
    _cpt++;
    return *_it++;
}

} /* namespace libgexf */