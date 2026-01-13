/*

			*** New edition ***
Now supports tab character as well as spaces in the formatting.
*/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	if( argc !=3 ) {
		fprintf(stderr,"Error: Please enter an input and an output file name seperated with space after the program executable name\n");
	
	return 1;

	}
   FILE *inputFile = fopen(argv[1], "r");
   FILE *outputFile = fopen(argv[2], "w");

   if( inputFile == NULL) {
	 fprintf(stderr, "Error: Could not open the input file %s\n", argv[1]);
	   return 1;
   }

   if(outputFile == NULL){
	   fprintf(stderr,"Error: Could no open the output file %s\n", argv[2]);
           fclose(inputFile);
           return 1;
   }	   

	char buffer[256];
	char customerName[100], accountNumber[100], reportDate[100];
	char stockName[50]; 
	int sharesHeld;
	double openPrice, highPrice, lowPrice, closePrice, stockValue;
       
	fgets(buffer, sizeof(buffer), inputFile);
	sscanf(buffer, "Customer Name%*[\t ]|%*[\t ]%[^\n]", customerName);

	fgets(buffer, sizeof(buffer), inputFile);
	sscanf(buffer, "Account Number%*[\t ]|%*[\t ]%[^n]", accountNumber);

	fgets(buffer, sizeof(buffer), inputFile);
	sscanf(buffer, "Report Date%*[\t ]|%*[\t ]%[^\n]", reportDate);

	fgets(buffer, sizeof(buffer), inputFile);
	sscanf(buffer, "Stock Name%*[\t ]|%*[\t ]%[^\n]", stockName);

	fgets(buffer, sizeof(buffer), inputFile);
	sscanf(buffer, "Shares Held%*[\t ]|%*[\t ]%d", &sharesHeld);

	fgets(buffer, sizeof(buffer), inputFile);
	sscanf(buffer, "Opening Price%*[\t ]|%*[\t ]%lf", &openPrice);

	fgets(buffer, sizeof(buffer), inputFile);
	sscanf(buffer, "High Price%*[\t ]|%*[\t ]%lf", &highPrice);

	fgets(buffer, sizeof(buffer), inputFile);
	sscanf(buffer, "Low Price%*[\t ]|%*[\t ]%lf", &lowPrice);

	fgets(buffer, sizeof(buffer), inputFile);
	sscanf(buffer, "Closing Price%*[\t ]|%*[\t ]%lf", &closePrice);


	//value change caclationo
	stockValue = (closePrice - openPrice) * sharesHeld;
	char *gainOrLoss = stockValue >= 0 ? "Gain" : "Loss";
	stockValue = stockValue >= 0 ? stockValue : -stockValue;

	//Writing on output file

	fprintf(outputFile, "Customer: %s\n", customerName);
    	fprintf(outputFile, "Account: %s", accountNumber);
    	fprintf(outputFile, "Reporting Date: %s\n", reportDate);
	fprintf(outputFile,"%-10s %-15s %-15s %-s\n", "Stock", "Open Price", "Close Price", gainOrLoss);
	fprintf(outputFile,"%-10s %-15.2f %-15.2f %-.2f\n", stockName, openPrice, closePrice, stockValue);
        // File closing
	fclose(inputFile);
	fclose(outputFile);

	printf("The formatted data has been written in %s file.\n", argv[2]);
	return 0;
}



