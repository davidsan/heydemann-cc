#include <iostream>
#include <OPLabel.h>
#include <Program.h>
#include <OPExpression.h>
#include <OPRegister.h>
#include <OPImmediate.h>
#include <Cfg.h>


int main(int argc, char ** argv){
    Program p2(argv[1]) ;
    p2.display() ;
    p2.comput_function();
    cout << "nb function " << p2.nbr_func() << endl;
    Function * fct = p2.get_function(0);
    fct -> comput_basic_block();
    fct -> comput_label();
    fct -> comput_succ_pred_BB();
    fct->display();

    for (int i = 0; i < fct->nbr_BB(); ++i) {
        Basic_block * BB = fct -> get_BB(i);
        BB ->display();
        Dfg * dfg = new Dfg(BB);
        char numstr[64];
        sprintf(numstr, "./tmp/graph_dfg%d.dot", i);
        dfg->restitute(NULL,numstr, true);
        cout << "temps critique : "<< dfg->get_critical_path() << endl;
        dfg->scheduling();
        dfg->display_scheduled_instr();
    }
}
