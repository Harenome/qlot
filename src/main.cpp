#include <iostream>

#include "magasin.hpp"

int main (int argc, char ** argv)
{
    std::cout << "QloT" << std::endl << std::endl;

    /* reference_article r (12345678); */
    date d;
    /* article a (r, 50.0, 100.0, d); */

    /* pourcentage p (15); */
    /* article_stock s (a.reference (), 10, p); */

    /* article_affichage f (a, s); */

    /* std::cout << f << std::endl; */

    vente v (d);
    vente v2 (v);
    vente v3 (d);
    std::cout << v << std::endl;
    std::cout << v2 << std::endl;
    std::cout << v3 << std::endl;

    return 0;
}
