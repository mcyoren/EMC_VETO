 #include "TFile.h"
#include "TCanvas.h"
#include "TH1.h"
#include <iostream>
#include "TStyle.h"

struct MyEvent {
    int n_gammas;
    int n_charged;

    double bbc_vertex;;

    double p_orig[3];

    vector<double> *g_es;
    vector<double> *g_xs;
    vector<double> *g_ys;
    vector<double> *g_zs;

    vector<int> *g_ytowers;
    vector<int> *g_ztowers;

    vector<double> *g_chi2s;
    vector<double> *g_probs;

    vector<int> *g_arms;
    vector<int> *g_secs;

    vector<int> *g_ids;
    vector<vector<double> > *tower_ids;

    vector<int> *trk_ids;
    vector<double> *trk_emcxs;
    vector<double> *trk_emcys;
    vector<double> *trk_emczs;

    void set_to_null() {
        n_gammas = 0;
        n_charged = 0;
        bbc_vertex = 0.0;

        p_orig[0] = 0.0;
        p_orig[1] = 0.0;
        p_orig[2] = 0.0;

        g_es=0;
        g_xs=0;
        g_ys=0;
        g_zs=0;
        g_arms=0;
        g_secs=0;
        g_ids=0;
        tower_ids=0;
        g_ytowers=0;
        g_ztowers=0;
        g_chi2s=0;
        g_probs=0;
        trk_ids=0;
        trk_emcxs=0;
        trk_emcys=0;
        trk_emczs=0;

        return;
    };
};


struct MyEvent_Write {
    int n_gammas;
    int n_charged;

    double bbc_vertex;;

    double p_orig[3];

    vector<double> g_es;
    vector<double> g_xs;
    vector<double> g_ys;
    vector<double> g_zs;

    vector<int> g_ytowers;
    vector<int> g_ztowers;

    vector<double> g_chi2s;
    vector<double> g_probs;

    vector<int> g_arms;
    vector<int> g_secs;

    vector<int> g_ids;
    vector<vector<double> > tower_ids;

    vector<int> trk_ids;
    vector<double> trk_emcxs;
    vector<double> trk_emcys;
    vector<double> trk_emczs;

    void set_to_null() {
        n_gammas = 0;
        n_charged = 0;
        bbc_vertex = 0.0;

        p_orig[0] = 0.0;
        p_orig[1] = 0.0;
        p_orig[2] = 0.0;

        g_es.clear();
        g_xs.clear();
        g_ys.clear();
        g_zs.clear();

        g_arms.clear();
        g_secs.clear();

        g_ids.clear();
        tower_ids.clear();

        g_ytowers.clear();
        g_ztowers.clear();

        g_chi2s.clear();
        g_probs.clear();

        trk_ids.clear();
        trk_emcxs.clear();
        trk_emcys.clear();
        trk_emczs.clear();

        return;
    };
};
