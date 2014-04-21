#include <iostream>
#include <OPLabel.h>
#include <Program.h>
#include <OPExpression.h>
#include <OPRegister.h>
#include <OPImmediate.h>
#include <Cfg.h>

int main(int argc, char ** argv) {
    Program p2(argv[1]);
    p2.comput_function();
    Function * fct = p2.get_function(0);
    fct->comput_basic_block();
    fct->comput_label();
    fct->comput_succ_pred_BB();
    Basic_block * BB = fct->get_BB(0);
    BB->display();
    list<int> l;
    BB->register_rename(l);
    BB->display();
}
