#include <cstdlib>
#include "List.h"


int main()
{
  Recipe Sandwich("Sandwich", 5, 10);
  Sandwich.setRecipeName("Sandwich");
  Sandwich.setCookingTime(5);
  Sandwich.setPreparationTime(10);
  Sandwich.addIngredient("Bread");
  Sandwich.addIngredient("Cheese");
  Sandwich.addIngredient("Ham");
  Sandwich.getRecipeName();
  Sandwich.getCookingTime();
  Sandwich.getPreparationTime();
  Sandwich.getIngredientSize();
  Sandwich.printIngredients();
  return 0;
}