﻿#include <Node_dfg.h>

Node_dfg::Node_dfg(Instruction* i1 ){
   _inst = i1;
   _nbr_descendant=0;
   _poids = 0;
}

Node_dfg::~Node_dfg(){
}

Arc_t *Node_dfg::get_arc(int index){

   list<Arc_t*>::iterator it;
   it=_arc.begin();

   if(index< (int)_arc.size()){
      for (int i=0; i<index; i++ ) it++;
      return *it;
   }
   else
      return NULL;

}

//arcs = successeurs
list<Arc_t*>::iterator Node_dfg::arcs_begin(){
   return _arc.begin();
}

list<Arc_t*>::iterator Node_dfg::arcs_end(){
   return _arc.end();
}

int Node_dfg::get_nb_arcs(){
   return _arc.size();
}

Instruction *Node_dfg::get_instruction(){
   return _inst;
}

void Node_dfg::add_arc(Arc_t* u){
   _arc.push_back(u);
}

void Node_dfg::add_predecesseur(Node_dfg*n){
   _pred.push_back(n);
}

int Node_dfg::nb_preds(){
   return (int) _pred.size();
}

list<Node_dfg*>::iterator Node_dfg::pred_begin(){
   return _pred.begin();
}

list<Node_dfg*>::iterator Node_dfg::pred_end(){
   return _pred.end();
}

void Node_dfg::set_instruction( Instruction* i1){
   _inst = i1;
}



void Node_dfg::set_weight( int w ){
   _poids = w;
}

int Node_dfg::get_weight( ){
   return _poids;
}

void Node_dfg::set_nb_descendant(int descent){
   _nbr_descendant=descent;
}

int Node_dfg::get_nb_descendant(){
   return _nbr_descendant;

}

void Node_dfg::set_tready(int t){
   _tready=t;
}

int Node_dfg::get_tready(){
   return _tready;
}

void Node_dfg::compute_nb_descendant(){
   list<Node_dfg *>::iterator it;
   Node_dfg * node;
   for(it = pred_begin(); it != pred_end(); it++) {
      node = *it;
      node->addElem(this);
      node->compute_nb_descendant();
   }
}


bool containsNode(list<Node_dfg*>* l, Node_dfg* n){
   list<Node_dfg*>::iterator it;

   for(it=l->begin(); it!= l->end(); it++){
      if( (*it)==n ){
	 return true;
      }
   }
   return false;
}

void Node_dfg::addElem(Node_dfg* node) {
   if (!containsNode(&_desc, node)) {
      _desc.push_back(node);
   }
}

void Node_dfg::merge_desc() {
   list<Node_dfg *>::iterator it;
   list<Node_dfg *>::iterator it2;
   Node_dfg * node;
   for(it = pred_begin(); it != pred_end(); it++) {
      node = *it;
      for (it2 = _desc.begin(); it2!= _desc.end();it2++) {
         node->addElem(*it2);
      }
      node->merge_desc();
   }
}

int Node_dfg::nb_desc_in_list() {
   return _desc.size();
}
