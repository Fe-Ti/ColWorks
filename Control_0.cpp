#include <iostream>
#include <string>
#include <vector>
// letters sorted by frequency (just becase)
// const std::vector<char> letters_by_freq{E,T,A,O,I,N,S,H,R,D,L,C,U,M,W,F,G,Y,P,B,V,K,J,X,Q,Z}

// Modified odd-even algorithm for sorting the answer
// I chose odd-even sort, because I'd written it before
void sort_answer(std::vector<int>& vec, std::string& str) {  
    int vec_len = vec.size(), is_vec_sorted = 0;            
    while (!(is_vec_sorted)) {
        is_vec_sorted = 1;
        for (int i=1; i < vec_len - 1; i += 2) {
            if (vec[i] > vec[i + 1]) {
                std::swap(vec[i], vec[i+1]);
                std::swap(str[i], str[i+1]);
                is_vec_sorted = 0;
                }
            }
        for (int i=0; i < vec_len - 1; i += 2) {
            if (vec[i] > vec[i + 1]) {
                std::swap(vec[i], vec[i+1]);
                std::swap(str[i], str[i+1]);
                is_vec_sorted = 0;
                }
            }
        }
    }

int main() {
//  there is a hardcoded text, 
//  because I didn't want to mess with copying the text multiple times
//  if something goes wrong (I've done this just for time saving and laziness)
    std::string text = "PIBIE KO IE IXNLKBMUIZW, WX OVXKEZ WT KOUIEQO, WE VLM MIOVMXE MQZM WT IOKI. VLMXM IXM TWCX RIKE KOUIEQO – LWHHIKQW, LWEOLC, OLKHWHC IEQ HYCOLC. VLMXM IXM IUOW EMIXUY 4,000 ORIUUMX KOUIEQO, VWW! PIBIE”O EMIXMOV RIKEUIEQ EMKZLJWXO IXM VLM OKJMXKIE XMZKWE WT XCOOKI KE VLM EWXVL, IEQ HWXMI IEQ NLKEI TIXVLMX OWCVL. IURWOV TWCX-TKTVLO WT PIBIE KO NWAMXMQ DKVL RWCEVIKEO. VLM PIBIEMOM IUBO XCE QWDE VLM NMEVXM WT VLM UIXZMOV KOUIEQ, LWEOLC. VLM LKZLMOV BMIH IEQ PIBIE’O RWOV TIRWCO RWCEVIKE KO RWCEV TCPK, I NWEM-OLIBMQ AWUNIEW NWEOKQMXMQ OINXMQ JY RIEY PIBIEMOM. PIBIE NIE JM I QIEZMXWCO BUINM. VLXMM WT VLM VMNVWEKN BUIVMO VLIV TWXR VLM MIXVL”O NXCOV RMMV EMIXJY IEQ WTVME RWAM IZIKEOV MINL WVLMX, NICOKEZ MIXVLFCIHMO. RWXM VLIE I VLWCOIEQ MIXVLFCIHMO LKV PIBIE MAMXY YMIX. PIBIE IUOW LIO IJWCV 200 AWUNIEWMO, 60 WT DLKNL IXM OVKUU INVKAM. VLM PIBIEMOM BMWBUM LIAM I QMMB ITTMNVKWE TWX VLM JMICVY WT VLM UIEQONIBM. VLM IENKMEV OLKEVW XMUKZKWE OIYO EIVCXIU TMIVCXMO UKHM RWCEVIKEO, DIVMXTIUUO IEQ TWXMOVO LIAM VLMKX WDE OBKXKV WX OWCU. PIBIE KO LWRM VW OWRM DWEQMXTCU DKUQUKTM! OWRM WT VLM NWCEVXY’O RWOV KENXMQKJUM NXMIVCXMO KENUCQM VLM OKHI QMMX, XMQ-NXWDEMQ NXIEM, OVMUUIX’O OMI MIZUM IEQ WEM WT VLM NWWUMOV NXKVVMXO WE VLM BUIEMV...VLM PIBIEMOM RINIFCM RWEHMY! RWOV WT PIBIE KO NWAMXMQ JY NWCEVXYOKQM – JCV DKVL RWXM VLIE 100 RKUUKWE BMWBUM UKAKEZ KE OCNL I ORIUU BUINM, OIQUY, DKUQUKTM LIO OCTTMXMQ. IUVLWCZL BWUUCVKWE KO EWD VKZLVUY NWEVXWUUMQ, WAMX VLM YMIXO, XWIQ JCKUQKEZ IEQ WVLMX LCRIE INVKAKVKMO LIAM LIXRMQ EIVCXIU LIJKVIVO. VWQIY, IJWCV 136 OBMNKMO KE PIBIE IXM UKOVMQ IO MEQIEZMXMQ. WTT VLM NWIOV WT VLKO KENXMQKJUM NWCEVXY, VLM DIXR VOCOLKRI NCXXMEV TUWDO TXWR VLM OWCVL KEVW VLM OMI WT PIBIE, DLMXM KV RMMVO I NWUQMX NCXXMEV TXWR VLM EWXVL. IO I XMOCUV WT VLM RKGKEZ WT QKTTMXMEV DIVMXO, VLM OMIO IXWCEQ PIBIE IXM AMXY XKNL KE TKOL IEQ WVLMX OMI UKTM. NWWU!";

    std::string letters = "";
    std::vector<int> l_freq{};

    for (char i : text) {   // counting letters
        if (std::isalpha(i)) {
            if (letters.find(i) == std::string::npos) {
                letters.push_back(i);
                l_freq.push_back(1);
                }
            else {
                l_freq[letters.find(i)]+=1;
                }
            }
        }

    sort_answer(l_freq, letters);   // sorting
    //  the idea was to sort letters in another direction,
    //  but I had limited time, so who cares

    for (char i : letters) { // printing
        std::cout << l_freq[letters.find(i)] << " - " << i << std::endl;
        }

    return 0;
    }
