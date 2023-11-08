#include "SimFrac.h"


void SimFrac (char simtree[200], char embedtree[200], char outfile[200]){

    MyEvent event1, event2;
    
     TFile *fileopen1 = new TFile(simtree,"Read");
  
    TTree *tree1 = (TTree*) fileopen1->Get("AnalysisTree0");

    tree1->SetBranchAddress("n_gammas", &event1.n_gammas);
    tree1->SetBranchAddress("n_charged", &event1.n_charged);
    tree1->SetBranchAddress("bbc_vertex", &event1.bbc_vertex);
    tree1->SetBranchAddress("p_orig", &event1.p_orig);
    tree1->SetBranchAddress("g_es",  &event1.g_es);
    tree1->SetBranchAddress("g_xs", &event1.g_xs);
    tree1->SetBranchAddress("g_ys", &event1.g_ys);
    tree1->SetBranchAddress("g_zs", &event1.g_zs);
    tree1->SetBranchAddress("g_arms", &event1.g_arms);
    tree1->SetBranchAddress("g_secs", &event1.g_secs);
    tree1->SetBranchAddress("g_chi2s", &event1.g_chi2s);
    tree1->SetBranchAddress("g_probs", &event1.g_probs);
    tree1->SetBranchAddress("g_ytowers", &event1.g_ytowers);
    tree1->SetBranchAddress("g_ztowers", &event1.g_ztowers);
    tree1->SetBranchAddress("g_ids", &event1.g_ids);
    tree1->SetBranchAddress("tower_ids", &event1.tower_ids);
    tree1->SetBranchAddress("trk_ids", &event1.trk_ids);
    tree1->SetBranchAddress("trk_emcxs", &event1.trk_emcxs);
    tree1->SetBranchAddress("trk_emcys", &event1.trk_emcys);
    tree1->SetBranchAddress("trk_emczs", &event1.trk_emczs);
    event1.set_to_null();
    tree1->GetEntry(4);


    //fileopen1->Close();

event2.set_to_null();
    TFile *fileopen2 = new TFile(embedtree,"Read");

    
    TTree *tree2 = (TTree*) fileopen2->Get("AnalysisTree");

    tree2->SetBranchAddress("n_gammas", &event2.n_gammas);
    tree2->SetBranchAddress("n_charged", &event2.n_charged);
    tree2->SetBranchAddress("bbc_vertex", &event2.bbc_vertex);
    tree2->SetBranchAddress("p_orig", &event2.p_orig);
    tree2->SetBranchAddress("g_es",  &event2.g_es);
    tree2->SetBranchAddress("g_xs", &event2.g_xs);
    tree2->SetBranchAddress("g_ys", &event2.g_ys);
    tree2->SetBranchAddress("g_zs", &event2.g_zs);
    tree2->SetBranchAddress("g_arms", &event2.g_arms);
    tree2->SetBranchAddress("g_secs", &event2.g_secs);
    tree2->SetBranchAddress("g_chi2s", &event2.g_chi2s);
    tree2->SetBranchAddress("g_probs", &event2.g_probs);
    tree2->SetBranchAddress("g_ytowers", &event2.g_ytowers);
    tree2->SetBranchAddress("g_ztowers", &event2.g_ztowers);
    tree2->SetBranchAddress("g_ids", &event2.g_ids);
    tree2->SetBranchAddress("tower_ids", &event2.tower_ids);
    tree2->SetBranchAddress("trk_ids", &event2.trk_ids);
    tree2->SetBranchAddress("trk_emcxs", &event2.trk_emcxs);
    tree2->SetBranchAddress("trk_emcys", &event2.trk_emcys);
    tree2->SetBranchAddress("trk_emczs", &event2.trk_emczs);
    event2.set_to_null();
    tree2->GetEntry(4);



    MyEvent_Write event;

    
    TFile *fileopen3 = new TFile(outfile,"Recreate");

    TTree *tree = new TTree("AnalysisTreeEmbed", "AnalysisTreeEmbed");

    tree->Branch("n_gammas", &event.n_gammas, "n_gammas/I");
    tree->Branch("n_charged", &event.n_charged, "n_charged/I");

    tree->Branch("bbc_vertex", &event.bbc_vertex, "bbc_vertex/D");

    tree->Branch("p_orig", event.p_orig, "p_orig[3]/D");

    tree->Branch("g_es",  &event.g_es);
    tree->Branch("g_xs", &event.g_xs);
    tree->Branch("g_ys", &event.g_ys);
    tree->Branch("g_zs", &event.g_zs);

    tree->Branch("g_arms", &event.g_arms);
    tree->Branch("g_secs", &event.g_secs);

    tree->Branch("g_chi2s", &event.g_chi2s);
    tree->Branch("g_probs", &event.g_probs);

    tree->Branch("g_ytowers", &event.g_ytowers);
    tree->Branch("g_ztowers", &event.g_ztowers);

    tree->Branch("g_ids", &event.g_ids);
    tree->Branch("tower_ids", &event.tower_ids);

    tree->Branch("trk_ids", &event.trk_ids);
    tree->Branch("trk_emcxs", &event.trk_emcxs);
    tree->Branch("trk_emcys", &event.trk_emcys);
    tree->Branch("trk_emczs", &event.trk_emczs);

    
    for (int j = 0; j < tree1->GetEntries(); j++)
    {

        tree1->GetEntry(j);
        tree2->GetEntry(j);
        
        event.p_orig[0] = event1.p_orig[0];
        event.p_orig[1] = event1.p_orig[1];
        event.p_orig[2] = event1.p_orig[2];

        int n_gammas1 = event1.n_gammas;
        event.n_charged = event1.n_charged;
        event.bbc_vertex = event1.bbc_vertex;

        //cout<<event1.n_charged<<" == "<<event2.n_charged<<endl;;

        //cout<<n_gammas1<<endl;
        const int n_gammas2 =  event2.n_gammas;
        int isMerged[n_gammas2];
        for (int i : isMerged) i=0;
        
        vector<double> tower_ids1;
        for (int i_gamma = 0; i_gamma < n_gammas1; i_gamma++) 
        {
            if(i_gamma>2000) break;
            for (int itower=0; itower < event1.tower_ids->at(i_gamma).size(); itower++)
            {
                //cout<<i_gamma<<" "<<event1.tower_ids->at(i_gamma).at(itower)<<" "<<endl;
                tower_ids1.push_back(event1.tower_ids->at(i_gamma).at(itower));
            }
        }

        int indexes[n_gammas2];
        for (int i_gamma2 = 0; i_gamma2 < n_gammas2; i_gamma2++) 
        {   
            indexes[i_gamma2]=0;
            for (int itower=0; itower < event2.tower_ids->at(i_gamma2).size(); itower++)
            {
                for (double id1 : tower_ids1)
                {
                    if (abs(event2.tower_ids->at(i_gamma2).at(itower) - id1)<0.9) indexes[i_gamma2]=1;
                    //cout<<id1<<" "<<event2.tower_ids->at(i_gamma2).at(itower)<<" "<<endl;
                }
            }
            if (indexes[i_gamma2]==1)
            {
                event.g_secs.push_back(event2.g_secs->at(i_gamma2));
                event.g_arms.push_back(event2.g_arms->at(i_gamma2));
                event.g_es.push_back(event2.g_es->at(i_gamma2));
                event.g_chi2s.push_back(event2.g_chi2s->at(i_gamma2));
                event.g_probs.push_back(event2.g_probs->at(i_gamma2));
                event.g_xs.push_back(event2.g_xs->at(i_gamma2));
                event.g_ys.push_back(event2.g_ys->at(i_gamma2));
                event.g_zs.push_back(event2.g_zs->at(i_gamma2));
                event.g_ytowers.push_back(event2.g_ytowers->at(i_gamma2));
                event.g_ztowers.push_back(event2.g_ztowers->at(i_gamma2));
                event.g_ids.push_back(event2.g_ids->at(i_gamma2));
                event.tower_ids.push_back(event2.tower_ids->at(i_gamma2));
            }
        }
        int total_gammas = 0;
        for (int i = 0; i < n_gammas2; i++)
        {
           if(indexes[i]==1) total_gammas++;
        }
        event.n_gammas = total_gammas;
        for (int i = 0; i < event1.n_charged; i++)
        {
            event.trk_ids.push_back(event1.trk_ids->at(i));
            event.trk_emcxs.push_back(event1.trk_emcxs->at(i));
            event.trk_emcys.push_back(event1.trk_emcys->at(i));
            event.trk_emczs.push_back(event1.trk_emczs->at(i));
        }
        
        
        //cout<<event.bbc_vertex<<" "<<event.g_es.size()<<" "<<event.tower_ids[0].size()<<endl;
        //event.trk_ids = event1.trk_ids;
        //event.trk_emcxs = event1.trk_emcxs;
        //event.trk_emcys = event1.trk_emcys;
        //event.trk_emczs = event1.trk_emczs;

        tree->Fill();
        event.set_to_null();
    }
    fileopen1->Close();
    fileopen2->Close();
    tree->Write();
    fileopen3->Close();

}

