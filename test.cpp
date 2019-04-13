#include <cstdlib>
#include "RecipeList.h"

using std::cout;
using std::endl;

int main()
{
  RecipeList currentList = RecipeList();

  currentList.addRecipe();
  Recipe* temporary = currentList.findRecipe("val");
  temporary->printRecipeName();

  temporary->getRecipeName();
  temporary->printIngredients();
  currentList.removeRecipe("val");
  currentList.findRecipe("val");
  return 0;
}
