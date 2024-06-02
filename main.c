/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bworrawa <bworrawa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 15:18:06 by bworrawa          #+#    #+#             */
/*   Updated: 2024/06/01 22:33:10 by bworrawa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>


int is_valid_column(int **grid, int c, int size)
{
    int i;
    int sum = 0;
    int check_sum = 0;

    i = 0;
    while (i < size)
    {
        if( grid[i][c] == 0) {
            return (0); 
        }
        sum += grid[i][c];
        check_sum += i + 1;
        i++;
    }
    if(sum != check_sum)
        return (0);
    return (1);
}
int is_valid_row(int **grid, int r, int size)
{
    int i;
    int sum = 0;
    int check_sum = 0;

    i = 0;
    while (i < size)
    {
        if( grid[r][i] == 0) {
            return (0); 
        }
        sum += grid[r][i];
        check_sum += i + 1;
        i++;
    }
    if(sum != check_sum)
        return (0);
    return (1);
}

int get_ltr_visible_boxes(int *arr, int size)
{
    int i;
    int sight_level;
    int boxes; 

    sight_level = 0;
    i = 0;
    boxes = 0;
    while ( i < size )
    {
        if( arr[i] > sight_level ) {
            boxes ++;
            sight_level = arr[ i ];
        }
        i++;
    }
    return boxes;    
}

int get_rtl_visible_boxes(int *arr, int size)
{
    int i;
    int sight_level;
    int boxes; 

    sight_level = 0;
    i = size - 1;
    boxes = 0;
    while ( i >= 0  )
    {
        if( arr[i] > sight_level ) {
            boxes ++;
            sight_level = arr[ i ];
        }
        i--;
    }
    return boxes;    
}

int get_ttb_visible_boxes(int **grid, int size , int c) {
    
    int i;
    int sight_level;
    int boxes; 

    sight_level = 0;
    i = 0;
    boxes = 0;
    while ( i < size )
    {
        if( grid[i][c] > sight_level ) {
            boxes ++;
            sight_level = grid[ i ][c];
        }
        i++;
    }
    return boxes;    
}

int get_btt_visible_boxes(int **grid, int size , int c) {
    
    int i;
    int sight_level;
    int boxes; 

    sight_level = 0;
    i = size - 1;
    boxes = 0;
    while ( i >= 0 )
    {
        if( grid[i][c] > sight_level ) {
            boxes ++;
            sight_level = grid[ i ][c];
        }
        i--;
    }
    return boxes;    
}


int is_visibility_correct(int **grid, int *subjects, int size, int pos)
{
    int r;
    int c;
    int cur_r;
    int visibles;

    r = pos / size;
    c = pos % size;
    
    
    // Left to Right
    cur_r = 0;
    visibles = 0;
    while (cur_r < size) {
        
    }
    
    return (0);
}

int is_valid_coord(int **grid, int *subjects, int size, int pos)
{
    int r;
    int c;
    
    r = pos / size;
    if( !is_valid_row(grid, r , size))
        return (0);
    c = pos % size;
    if (!is_valid_column(grid, c , size))
        return (0);
    
    printf("NEED CHECK VISIBILITY TOP/DOWN/LEFT/RIGHT\n\n");
    
    return (1);

}

int get_subjects(char *str, int *ret)
{
    const int   int_size = 4;
    int     ctr;
    int     size;
    int     checking_size; 

    ctr = 0;
    size = 0;
    while( str[ctr] != '\0')
    {
        if (ctr % 2 == 0)
        {
            ret[size] = str[ctr] - '0';
            size++;
        } 
        ctr++;
    }
    printf("DONE?");
    checking_size = 4;
    while( checking_size <= 9)
    {
        if( checking_size * checking_size == size ) {
            return checking_size;
        }
        if( checking_size * checking_size > size) {
            return (0);
        }
        checking_size ++;
    }

    return (0);
}


void setup_grid(int *grid[], int size)
{
    int r;
    int c;

    r = 0;
    while (r < size )
    {
        c = 0;    
       while (c < size)
        {
            grid[r][c] = 0;
            c++;
        }
        r++;
    }
}

void display_grid(int **grid, int size)
{

    int r;
    int c;
    
    r = 0;

    printf("display_grid()\n\n");
    while ( r < size )
    {   c = 0;
        while (c < size)
        {
            printf("%d ", grid[r][c]);
            c++;
        }   
        printf("\n");
        r ++;
    }
    printf("\n");
}

void display_grid_with_subjects(int **grid, int size, int *subjects)
{
    
    int r;
    int c;
    int hr;
    int hc;
    
    r = 0;

    printf("display_grid_with_subjects()()\n\n");
    while ( r < size )
    {   
        if (r == 0)
        {
            hc = 0;
            printf("  ");
            while ( hc < size) {
                printf("%d ", subjects[ hc ]);
                hc++;
            }
            printf("\n");
            
        }
        c = 0;
        while (c < size)
        {

            if( c == 0) 
                printf("%d ", subjects[(2 * size) + r]);
            printf("%d ", grid[r][c]);
            c++;
        }   
        printf("%d ", subjects[(3 * size) + r]);
        printf("\n");
        r ++;
    }
    c = 0;
    printf("  ");
    while (c < size)
    {
        printf("%d ", subjects[(1 * size) + c]);
        c++;
    }
    printf("\n");
    
}

int fill_columns(int **grid, int col, int size, char direction)
{
    int ctr;
    
    if(direction == 'a')
    {
        ctr = 0;
        while (ctr < size)
        {
            grid[ ctr ][col] = ctr +1; 
            ctr++;
        }
    }
    else
    {
        ctr = size - 1;
        while(ctr >= 0) {
            grid[ ctr ][col] = size - ctr;
            ctr --;
        }        
    }
    return size;
}
int fill_rows(int **grid, int row, int size, char direction)
{
    int ctr;
    
    if(direction == 'a')
    {
        ctr = 0;
        while (ctr < size)
        {
            grid[ row  ][ctr] = ctr +1; 
            ctr++;
        }
    }
    else
    {
        ctr = size - 1;
        while(ctr >= 0) {
            grid[ row ][ctr] = size - ctr;
            ctr --;
        }        
    }
    return size;
}


int fill_the_sure_things(int **grid, int *subjects,int size)
{
    int i;
    int r;
    int c;

    i = 0;
    while( i < (size * 4)) {
        r = i / size;
        c = i % size;

        // can view all buildings
        if( r == 0 && subjects[i] == size) {
            // printf("filling column %d\n", c);
            fill_columns(grid,  c , size , 'a');           
        } 
        else if (r == 1 &&  subjects[i] == size) {
            //printf("filling column %d\n", c);
            fill_columns(grid,  c , size , 'd');
        } else if (r == 2 &&  subjects[i] == size) {
            fill_rows(grid, c , size , 'a');
        } else if (r == 3 &&  subjects[i] == size) {
            fill_rows(grid, c , size , 'd');
        }

        // next to the tallest building
        if( subjects[i] == 1) {
            printf("- matched min - %d %d\n" , r , c);

            if( r == 0)
                grid[r][c] = size;
            else if( r == 1)
                grid [ size - 1][c] = size;
            else if( r == 2)
                grid [ c ][0] = size;
            else if( r == 3)
                grid [ c ][ size - 1] = size;
                    
        }
        
        i++;
    }
    return i;
}

int verify_grid(int **grid,int *subjects, int size)
{
    return (1);
} 


int solve(int **grid, int *subjects,int size) 
{
    int  i;
    int out;
    
    printf("SOLVING TIME ....\n");
    i = 0;
    while( i < size * size )
    {

        out = is_valid_coord( grid, subjects , size , i);
        printf(" i = %d , out = %d \n", i , out);
        if (out == 0)
        {
            return (0);
        }
        
        i++;
        // if( i > 3 ) {
        //     printf("emergency brake\n\n");
        //     return (0);
        // }
    }

    
    return (1);
}

int main(){

    // from subject
    // char *str = "4 3 2 1 1 2 2 2 4 3 2 1 1 2 2 2";
    //  from https://www.puzzle-skyscrapers.com/ #363,454
    // easy one 
    char *str = "1 2 2 3 3 1 3 2 1 2 4 2 4 2 1 2";
    // char *str = "4 3 2 1 1 2 2 2 4 3 2 1 1 2 2 2 5 4 3 2 1 2 3 4 5";
    int subjects[81];
    int **grid;
    int size;

    int i;
    int j;
    
    size = get_subjects(str, subjects);
    
    grid = (int**)malloc((size) * 4);
    i = 0;
    while (i < size )
    {
        j = 0;
        while(j < size + 2) {
            grid[ i ] = (int *)malloc( (size) * 4);        
            j++;
        }
        i++;
    }

    printf("size = %d\n\n", size);

    // for(i=0; i<size * size;i++)
    // {
    //     printf("%d\n", subjects[i]);   
    // }
   
    setup_grid(grid, size);
    //printf("display()\n");
    //display_grid(grid, size);
    // fillColumn(grid, 0 , size , 'a');
    // fillColumn(grid, 1 , size , 'a');
    // fillColumn(grid, 3 , size , 'd');
    // fillRow(grid, 0 , size , 'a');

    fill_the_sure_things(grid , subjects , size);



    // manual fill
    grid[1][2] = 4;
    grid[3][2] = 1;
    
    grid[1][0] = 3;
    grid[3][0] = 2;
    grid[1][1] = 1;
    grid[1][3] = 2;
    grid[3][3] = 3;

    
    

    display_grid_with_subjects(grid, size, subjects);


    // printf(" is_valid_column(3) : %d\n", is_valid_column(grid , 2 , size));
    // printf(" is_valid_row(3) : %d\n", is_valid_row(grid , 0 , size));

    int boxes ;
    // printf("\n=====\nLeftToRight\n========\n");
    // boxes =  get_ltr_visible_boxes( grid[0], size);
    // printf(" visible boxes (LTR) for row [0] = %d\n", boxes);
    // boxes =  get_ltr_visible_boxes( grid[1], size);
    // printf(" visible boxes (LTR) for row [1] = %d\n", boxes);
    // boxes =  get_ltr_visible_boxes( grid[2], size);
    // printf(" visible boxes (LTR) for row [2] = %d\n", boxes);
    // boxes =  get_ltr_visible_boxes( grid[3], size);
    // printf(" visible boxes (LTR) for row [3] = %d\n", boxes); 
    // /// solve(grid, subjects , size );

    // printf("\n======\nRightToLeft\n========\n");
    // boxes =  get_rtl_visible_boxes( grid[0], size);
    // printf(" visible boxes (RTL) for row [0] = %d\n", boxes);
    // boxes =  get_rtl_visible_boxes( grid[1], size);
    // printf(" visible boxes (RTL) for row [1] = %d\n", boxes);
    // boxes =  get_rtl_visible_boxes( grid[2], size);
    // printf(" visible boxes (RTL) for row [2] = %d\n", boxes);
    // boxes =  get_rtl_visible_boxes( grid[3], size);
    // printf(" visible boxes (RTL) for row [3] = %d\n", boxes); 
    
    printf("\n======\nTop to Bottom\n========\n");
    boxes =  get_ttb_visible_boxes( grid, size , 0 );
    printf(" visible boxes (TTB) for row [0] = %d\n", boxes);
    boxes =  get_ttb_visible_boxes( grid, size , 1 );
    printf(" visible boxes (TTB) for row [1] = %d\n", boxes);
    boxes =  get_ttb_visible_boxes( grid, size , 2 );
    printf(" visible boxes (TTB) for row [2] = %d\n", boxes);
    boxes =  get_ttb_visible_boxes( grid, size , 3 );
    printf(" visible boxes (TTB) for row [3] = %d\n", boxes);

    printf("\n======\nBottom to Top\n========\n");
    boxes =  get_btt_visible_boxes( grid, size , 0 );
    printf(" visible boxes (TTB) for row [0] = %d\n", boxes);
    boxes =  get_btt_visible_boxes( grid, size , 1 );
    printf(" visible boxes (TTB) for row [1] = %d\n", boxes);
    boxes =  get_btt_visible_boxes( grid, size , 2 );
    printf(" visible boxes (TTB) for row [2] = %d\n", boxes);
    boxes =  get_btt_visible_boxes( grid, size , 3 );
    printf(" visible boxes (TTB) for row [3] = %d\n", boxes);
    
    free(grid);
    return 0; 
}
