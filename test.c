#include <stdio.h>

int main ()
{
  float designTimeHours, designTimeMinutes, designTimeSeconds, filamentPricePerKg, filamentUsedGrams, printTimeHours, printTimeMinutes, printTimeSeconds, laborCostPerHour, printCost, taxes, totalCostWithTaxes, filamentPrice, profit, totalDesignTime, totalPrintTime;

  printf("<-------------------------------------------->\n|                                           |\n| 3D PRINTING PRODUCT CALCULATOR            |\n|                                           |\n<-------------------------------------------->\n");
  printf("Enter the necessary data to calculate the total price of the 3D print.\n\n");
  printf("| -> How many hours were needed to DESIGN the 3D project?\n");
  do {
    scanf ("%f", &designTimeHours);
    if (designTimeHours < 0) {
      printf("Invalid quantity! Please enter a value greater than or equal to 0.\n");
    }
  } while (designTimeHours < 0);

  printf("| -> How many minutes were needed to DESIGN the 3D project?\n");
  do {
    scanf ("%f", &designTimeMinutes);
    if (designTimeMinutes < 0) {
      printf("Invalid quantity! Please enter a value greater than or equal to 0.\n");
    }
  } while (designTimeMinutes < 0);

  printf("| -> How many seconds were needed to DESIGN the 3D project?\n");
  do {
    scanf ("%f", &designTimeSeconds);
    if (designTimeSeconds < 0) {
      printf("Invalid quantity! Please enter a value greater than or equal to 0.\n");
    }
  } while (designTimeSeconds < 0);

  printf("| -> Enter the price per KILOGRAM of filament.\n");
  do {
    scanf("%f", &filamentPricePerKg);
    if (filamentPricePerKg <= 0) {
      printf("Invalid quantity! Please enter a value greater than 0.\n");
    }
  } while (filamentPricePerKg <= 0);

  printf ("| -> Now, input the amount of filament used. (In grams)\n");
  do {
    scanf ("%f", &filamentUsedGrams);	
    if (filamentUsedGrams <= 0) {
      printf("Invalid quantity! Please enter a value greater than 0.\n");
    }
  } while (filamentUsedGrams <= 0);

  printf ("| -> Next, provide the data about the 3D print time. (Hours, minutes, seconds, respectively) <- |\n\n");	
  printf ("| -> Input how many hours were spent printing.\n");
  do {
    scanf ("%f", &printTimeHours);
    if (printTimeHours < 0) {
      printf("Invalid quantity! Please enter a value greater than or equal to 0.\n");
    }
  } while (printTimeHours < 0);

  printf ("| -> Input how many minutes were spent printing.\n");
  do {
    scanf ("%f", &printTimeMinutes);
    if (printTimeMinutes < 0) {
      printf("Invalid quantity! Please enter a value greater than or equal to 0.\n");
    }
  } while (printTimeMinutes < 0);

  printf ("| -> Input how many seconds were spent printing.\n");
  do {
    scanf ("%f", &printTimeSeconds);		
    if (printTimeSeconds < 0) {
      printf("Invalid quantity! Please enter a value greater than or equal to 0.\n");
    }
  } while (printTimeSeconds < 0);

  printf ("| -> Enter the cost of labor (PER HOUR):\n");
  do { 
    scanf ("%f", &laborCostPerHour);
    if (laborCostPerHour <= 0) {
      printf("Invalid quantity! Please enter a value greater than 0.\n");
    }
  } while (laborCostPerHour <= 0);

  printf("| -> Enter the percentage of taxes:\n");
  do {
    scanf("%f", &taxes);
    if (taxes < 0) {
      printf("Invalid quantity! Please enter a value greater than or equal to 0.\n");
    }
  } while (taxes < 0);
  
  // Calculations
  totalDesignTime = (designTimeSeconds / 3600) + (designTimeMinutes / 60) + designTimeHours;
  totalPrintTime = (printTimeSeconds / 3600) + (printTimeMinutes / 60) + printTimeHours;
  printCost = (totalDesignTime * laborCostPerHour) + (totalPrintTime * laborCostPerHour) + (filamentPricePerKg * (filamentUsedGrams / 1000));
  
  if (taxes == 0) {
    printf("| -> No taxes were applied to the project.\n");
    totalCostWithTaxes = printCost;
  } else {
    totalCostWithTaxes = (printCost * (taxes / 100)) + printCost;
  }
  
  filamentPrice = (filamentPricePerKg * (filamentUsedGrams / 1000));
  profit = totalCostWithTaxes * 0.3;
  profit += totalCostWithTaxes;
  
  // Output
  printf("\n\n| -> FILAMENT PRICE: %.2f\n", filamentPrice);
  printf("| -> TOTAL PRICE: %.2f\n", totalCostWithTaxes);
  printf("| -> SUGGESTED SELLING PRICE: %.2f\n", profit);

  return 0;
}
