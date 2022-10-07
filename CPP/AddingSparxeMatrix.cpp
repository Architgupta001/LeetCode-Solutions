#include <iostream>
using namespace std;

struct element
{
      int row;
      int col;
      int value;
};

struct sparse
{
      int t_row;
      int t_col;
      int t_num;
      struct element *t_e;
};

void createSparseMatrix(struct sparse *m)
{
      cout << "Enter the Rows and Column of the Matrix :";
      cin >> m->t_row >> m->t_col;

      cout << "Enter the Number of the Non-Zero Elements :";
      cin >> m->t_num;

      m->t_e = new element[m->t_num];

      cout << "Enter the Elements at their Respective Position :";

      for (int i = 0; i < m->t_num; i++)
      {
            cout << "Row: ";
            cin >> m->t_e[i].row;
            cout << "Column: ";
            cin >> m->t_e[i].col;
            cout << "Value: ";
            cin >> m->t_e[i].value;
      }
}

struct sparse *addtionOfSparseMatrix(struct sparse *m1, struct sparse *m2)
{
      struct sparse *add;
      int i, j, k;
      i = j = k = 0;

      if (m1->t_row != m2->t_row || m1->t_col != m2->t_col)
      {
            return NULL;
      }
      else
      {
            add = new sparse;
            add->t_e = new element[m1->t_num + m2->t_num];

            while (i < m1->t_num && j < m2->t_num)
            {

                  if (m1->t_e[i].row < m2->t_e[j].row)
                  {
                        add->t_e[k++] = m1->t_e[i++];
                  }
                  else if (m1->t_e[i].row > m2->t_e[j].row)
                  {
                        add->t_e[k++] = m2->t_e[j++];
                  }

                  else
                  {
                        if (m1->t_e[i].col < m2->t_e[j].col)
                        {
                              add->t_e[k++] = m1->t_e[i++];
                        }
                        else if (m1->t_e[i].col > m2->t_e[j].col)
                        {
                              add->t_e[k++] = m2->t_e[j++];
                        }
                        else
                        {
                              add->t_e[k] = m1->t_e[i];
                              add->t_e[k++].value = m1->t_e[i++].value + m2->t_e[j++].value;
                        }
                  }
            }
            for (; i < m1->t_num; i++)
            {
                  add->t_e[k++] = m1->t_e[i];
            }
            for (; j < m2->t_num; j++)
            {
                  add->t_e[k++] = m2->t_e[j];
            }

            add->t_row = m1->t_row;
            add->t_col = m1->t_col;
            add->t_num = k;

            return add;
      }
}

void display(struct sparse m)
{
      int i, j, k = 0;

      for (i = 0; i < m.t_row; i++)
      {
            for (j = 0; j < m.t_col; j++)
            {
                  if (i == m.t_e[k].row && j == m.t_e[k].col)
                  {
                        cout << m.t_e[k++].value << " ";
                  }
                  else
                  {
                        cout << "0 ";
                  }
            }
            cout << endl;
      }
}

int main()
{
      struct sparse A, B, *C;
      createSparseMatrix(&A);
      createSparseMatrix(&B);
      C = addtionOfSparseMatrix(&A, &B);
      cout << "First Matrix  :" << endl;
      display(A);
      cout << "Second Matrix :" << endl;
      display(B);
      cout << "Sum of Matrix Additon Produces :" << endl;
      display(*C);
      return 0;
}
