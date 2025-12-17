#include "Header/data_seeding.h"
#include "Header/sales.h"

void startDataSeeding(adrSales &root)
{
    adrSales newSales;

    /* Seeding intial data */
    newSales = createElmSales(5, "Fujiati Keisha", "0208 2987 085", 1523154);
    insertNewSales(root, newSales);
    newSales = createElmSales(3, "Damayanti Dalima", "0406 1890 0566", 942031);
    insertNewSales(root, newSales);
    newSales = createElmSales(1, "Luhung Wicaksono", "0764 4058 1103", 442957);
    insertNewSales(root, newSales);
    newSales = createElmSales(2, "Rahayu Namaga", "(+62) 414 2295 113", 1938942);
    insertNewSales(root, newSales);
    newSales = createElmSales(7, "Ardiyanti Tri", "(+62) 256 9997 738", 1892571);
    insertNewSales(root, newSales);
    newSales = createElmSales(9, "Alamsyah Among", "(+62) 908 7366 633", 371187);
    insertNewSales(root, newSales);
}
