#include "List.h"


class RecipeList
{
public:
//Declaration
  RecipeList();
//setters
  void addRecipe(std::string rName);
  void removeRecipe(std::string rName);
  void changeRecipe(int select);

//getters
  int recipeAmount();
  bool listFull();
  bool listEmpty();
  //Search through recipes
private:
  std::vector<Recipe> listRecipe;
  Recipe* current;
  Recipe* nextRecipe;
  Recipe* previousRecipe;
};
