#include"matrix.h"
#include<iostream>


//beginning of matrix operations program

//constructor

Matrix::Matrix(unsigned r, unsigned c)
{
    //creating matrix
    this->rows=r;
    this->cols=c;
    matrix=new double*[this->rows];
    for(int i = 0;i<r;i++)
    {
        matrix[i]=new double[this->cols];
    }

    //set matrix to zeros

    for(int i=0;i<r;i++)
    {
        for(int j=0;c<j;j++)
        {
            matrix[i][j]=0;
        }
    }

    this->linearDeterminants=new double[3];
    for(int r=0;r<3;r++)
    {this->linearDeterminants[r]=-0.9;}
    this->denominator=-0.9;

}

//operator()

double& Matrix:: operator()(const unsigned r,const unsigned c)
{
    return this->matrix[r][c];
}

//const operator()

const double& Matrix::operator()(const unsigned r, const unsigned c) const
{
    return matrix[r][c];
}

//operator[]

Matrix Matrix::operator[](const unsigned r) const
{
    //create array that will hold the row selected
    double array[this->cols];
    for(int i =0;i<this->cols;i++)
    {
        array[i]=this->matrix[r][i];
    }

    // create matrix 1 by n, n=cols
    unsigned m =1;
    unsigned p=0; //the row of matrix const
    unsigned n=this->cols;
    Matrix x(m,n);
    for(int i=0;i<n;i++)
    {
        x(p,i)=array[i];
    }
    return x; 
}

//operator= 

const Matrix& Matrix::operator=(const Matrix &rhs)
{
    if(&rhs==this)
    {
        return *this;
    }
    for(int i =0;i<this->rows;i++)
    {
        delete [] matrix[i];
    }

    delete [] matrix;

    this->rows=rhs.getRows();
    this->cols=rhs.getCols();

    matrix=new double*[this->rows];
    for(int i = 0;i<this->rows;i++)
    {
        matrix[i]=new double[this->cols];
    }

    for(int r=0;r<this->rows;r++)
    {
        for(int c=0;c<this->cols;c++)
        {
            matrix[r][c]=rhs.matrix[r][c];
        }

    }
    delete [] linearDeterminants;
    this->linearDeterminants=new double[3];
    for(int r=0;r<3;r++)
    {this->linearDeterminants[r]=-0.9;}
    this->denominator=-0.9;

    for(int r=0;r<3;r++)
    {this->linearDeterminants[r]=rhs.linearDeterminants[r];}
    this->denominator=rhs.denominator;
    return *this;
}

//copy constructor

Matrix::Matrix(const Matrix &rhs)
{
    this->rows=rhs.getRows();
    this->cols=rhs.getCols();

    matrix=new double*[this->rows];
    for(int i = 0;i<this->rows;i++)
    {
        matrix[i]=new double[this->cols];
    }

    for(int i =0;i<this->rows;i++)
    {
        for(int j =0;j<this->cols;j++)
        {
            this->matrix[i][j]=rhs.matrix[i][j];
        }
    }
}

//extraction operator

istream& operator>>(istream& in,Matrix& input)
{
    for(int r=0;r<input.getRows();r++)
    {
        for(int c=0;c<input.getCols();c++)
        {
            in>>input.matrix[r][c];
        }
    }
    return in;
}

//insertion operator

ostream& operator<<(ostream& out, const Matrix& output )
{
    cout<<setprecision(3);
    for(int r=0;r<output.getRows();r++)
    {
        for(int c=0;c<output.getCols();c++)
        {
            out<<setw(10)<<output.matrix[r][c];
        }
        cout<<endl;
    }
    return out;
}

//get rows

unsigned Matrix::getRows() const
{
    return this->rows;
}

//get columns

unsigned Matrix::getCols() const
{
    return this->cols;
}


/*

this section is for operation of the matrix
addition 
subtraction
multiplication
power

*/

//operator+

Matrix operator*(const double& multipler, const Matrix &rhs)
{
    Matrix obj(rhs.getRows(),rhs.getCols());

    for(int r =0;r<rhs.getRows();r++)
    {
        for(int c=0;c<rhs.getCols();c++)
        {
            obj.matrix[r][c]=multipler*rhs.matrix[r][c];
        }
    }
    return obj;
}
Matrix Matrix::operator+(const Matrix &rhs)
{
    if(this->rows != rhs.getRows() || this->cols!=rhs.getCols())
    {
        cout<<"Error: adding matrices of different dimensionality"<<endl;
        return *this;
    }else
    {
        //implement the operation
        Matrix obj(rhs.getRows(),rhs.getCols());

        for(int r=0;r<rhs.getRows();r++)
        {
            for(int c=0;c<rhs.getCols();c++)
            {
                obj.matrix[r][c]=this->matrix[r][c]+rhs.matrix[r][c];
            }
        }

        return obj ;
    }
}

//operator+=

Matrix& Matrix::operator+=(const Matrix &rhs)
{
    if(this->rows != rhs.getRows() || this->cols!=rhs.getCols())
    {
        cout<<"Error: adding matrices of different dimensionality"<<endl;
        return *this;
    }else
    {
        //implement the operation
        for(int r=0;r<rhs.getRows();r++)
        {
            for(int c=0;c<rhs.getCols();c++)
            {
                this->matrix[r][c]=this->matrix[r][c]+rhs.matrix[r][c];
            }
        }
    return *this;
    }
    
}

//operator-

Matrix Matrix::operator-(const Matrix &rhs)
{
    if(this->rows != rhs.getRows() || this->cols!=rhs.getCols())
    {
        cout<<"Error: subtracting matrices of different dimensionality"<<endl;
        return *this;
    }else
    {
        //implement the operation
        Matrix obj(rhs.getRows(),rhs.getCols());

        for(int r=0;r<rhs.getRows();r++)
        {
            for(int c=0;c<rhs.getCols();c++)
            {
                obj.matrix[r][c]=this->matrix[r][c]-rhs.matrix[r][c];
            }
        }

        return obj ;
    }
    
    
}

//operator-=

Matrix& Matrix::operator-=(const Matrix &rhs)
{
    if(this->rows != rhs.getRows() || this->cols!=rhs.getCols())
    {
        cout<<"Error: subtracting matrices of different dimensionality"<<endl;
        return *this;
    }else
    {
        //implement the operation
        for(int r=0;r<rhs.getRows();r++)
        {
            for(int c=0;c<rhs.getCols();c++)
            {
                this->matrix[r][c]=this->matrix[r][c]-rhs.matrix[r][c];
            }
        }
    return *this;
    }
    
}

//scalar operator*

Matrix Matrix::operator*(const double &rhs)
{
    Matrix obj(this->getRows(),this->getCols());

        for(int r=0;r<this->getRows();r++)
        {
            for(int c=0;c<this->getCols();c++)
            {
                obj.matrix[r][c]=this->matrix[r][c]*rhs;
            }
        }

        return obj ;
}

//scalar operator*=

 Matrix& Matrix:: operator*=(const double &rhs)
 {      for(int r=0;r<this->getRows();r++)
        {
            for(int c=0;c<this->getCols();c++)
            {
                this->matrix[r][c]=this->matrix[r][c]*rhs;
            }
        }
    return *this;
 }

//scalar operator/

 Matrix Matrix::operator/(const double &rhs)
 {
     if(rhs==0)
     {
         cout<<"Error: division by zero"<<endl;
         return *this;
     }else{
         //operation implementation
         Matrix obj(this->getRows(),this->getCols());

        for(int r=0;r<this->getRows();r++)
        {
            for(int c=0;c<this->getCols();c++)
            {
                obj.matrix[r][c]=this->matrix[r][c]/rhs;
            }
        }

        return obj ;
     }

 }

// matrix operator*

    Matrix Matrix::operator*(const Matrix &rhs)
    {
        if(this->getCols() !=rhs.getRows())
        {
            cout<<"Error: invalid matrix multiplication"<<endl;
            return *this;
        }else{
            //operation implementation
            Matrix obj(this->getRows(),rhs.getCols());
            double out;
            for (int i = 0; i <this->getRows(); i++)
            {
                for(int j =0;j<rhs.getCols();j++)
                {
                    out=0.0;
                    for(int m = 0; m<this->getCols() ;m++)
                    {
                        out=out + this->matrix[i][m]* rhs.matrix[m][j];
                    }
                    obj.matrix[i][j]=out;
                }
                
            }
            return obj;
        }

    }

// matrix operator*=

    Matrix& Matrix:: operator*=(const Matrix &rhs)
    {
        if(this->getCols() !=rhs.getRows())
        {
            cout<<"Error: invalid matrix multiplication"<<endl;
            return *this;
        }else{
            //operation implementation
            Matrix obj(this->getRows(),rhs.getCols());

            double out;
            for (int i = 0; i <this->getRows(); i++)
            {
                for(int j =0;j<rhs.getCols();j++)
                {
                    out=0;
                    for(int m = 0; m<this->getCols() ;m++)
                    {
                        out+=this->matrix[i][m]* rhs.matrix[m][j];
                    }
                    obj.matrix[i][j]=out;
                }
                    
            }

            for(int i=0;i<this->getRows();i++)
            {
                delete [] matrix[i];
            }
            delete [] matrix;

            this->rows=this->getRows();
            this->cols=rhs.getCols();
            matrix=new double*[this->getRows()];
            for(int r=0;r<this->getRows();r++)
            {
                matrix[r]=new double[rhs.getCols()];
            }

            for(int r=0;r<this->getRows();r++)
                {
                    for(int c=0;c< rhs.getCols();c++)
                    {
                        this->matrix[r][c]=obj.matrix[r][c];
                    }
                }
            

        return *this;
        }

    }

// matrix operator^
    
    Matrix Matrix:: operator^(int pow)
    {
         if(this->getRows()!=this->getCols())
        {
            cout<<"Error: non-square matrix provided"<<endl;
            return *this;
        }else if(pow<0)
        {
            cout<<"Error: negative power is not supported"<<endl;
            return *this;
        }else{
            //operation implementation
            
             
            if(pow==0)
            {
                Matrix obj1(this->getRows(),this->getCols());
                for(int i =0;i<this->getRows();i++)
                {
                    for(int j =0;j<this->getCols();j++)
                    {
                        if(i==j)
                        {
                            obj1.matrix[i][j]=1;

                        }else
                        {
                           obj1.matrix[i][j]=0;
                        }
                    }
                }
                return obj1;

            }else if(pow==1)
            {
                
               return *this;
            }else if(pow>1)
            {
                Matrix obj1(this->getRows(),this->getCols());
                for(int i =0;i<this->getRows();i++)
                {
                    for(int j =0;j<this->getCols();j++)
                    {
                        obj1.matrix[i][j]=this->matrix[i][j];
                    }
                }

                for (int i = 1; i < pow; i++)
                {
                    obj1=obj1*obj1;
                }
            return obj1;
            }
            
        }

    }

// matrix operator^=
    
    Matrix& Matrix:: operator^=(int pow)
    {
        if(this->getRows() != this->getCols())
        {
            cout<<"Error: non-square matrix provided"<<endl;
            return *this;
        }else if(pow<0)
        {
            cout<<"Error: negative power is not supported"<<endl;
            return *this;
        }else if(pow==0)
        {
                for(int i =0;i<this->getRows();i++)
                {
                    for(int j =0;j<this->getCols();j++)
                    {
                        if(i==j)
                        {
                            this->matrix[i][j]=1;

                        }else
                        {
                           this->matrix[i][j]=0;
                        }
                    }
                }
                return *this;
        }else if(pow==1)
        {
            return *this;
        }else if(pow>1)
        {
            Matrix obj1(this->getRows(),this->getCols());
            for(int i =0;i<this->getRows();i++)
                {
                    for(int j =0;j<this->getCols();j++)
                    {
                        obj1.matrix[i][j]=this->matrix[i][j];
                    }
                }
            Matrix obj(this->getRows(),this->getCols());
            for(int i =0;i<this->getRows();i++)
                {
                    for(int j =0;j<this->getCols();j++)
                    {
                        obj.matrix[i][j]=this->matrix[i][j];
                    }
                }
            for (int i = 0; i < pow; i++)
            {
                obj1=obj1*obj;
            }
            
            for(int i = 0;i<this->getRows();i++)
                {
                    for(int j =0;j<this->getCols();j++)
                    {
                        this->matrix[i][j]=obj1.matrix[i][j];
                    }
                }

            return *this;
        }

    }


 /*
 This section focuses on the linear systems of equations implementing the cramers rule
 using operator overloading 
 */

//operator ~

double Matrix::operator~()
{
    if(this->getRows()==2 && this->getCols()==2)
    {
        double part1=this->matrix[0][0]*this->matrix[1][1];
        double part2=this->matrix[0][1]*matrix[1][0];
        this->denominator=part1-part2;

        return part1-part2;

    }else if(this->getRows()==3 && this->getCols()==3)
    {
        double part1=(this->matrix[1][1] * this->matrix[2][2])-(this->matrix[1][2] * this->matrix[2][1]);
        double part2=(this->matrix[1][0] * this->matrix[2][2])-(this->matrix[1][2] * this->matrix[2][0]);
        double part3=(this->matrix[1][0] * this->matrix[2][1])-(this->matrix[1][1] * this->matrix[2][0]);

        this->denominator=(this->matrix[0][0]*part1)-(this->matrix[0][1]*part2)+(this->matrix[0][2]*part3);
        
        return (this->matrix[0][0]*part1)-(this->matrix[0][1]*part2)+(this->matrix[0][2]*part3);
    }else{
        cout<<"Error: invalid matrix dimensions"<<endl;
        return 0;
    }
}

//*operator|

double* Matrix::operator|(Matrix &rhs)
{
    if(this->getRows()==this->getCols())
    {
        if(this->getRows()==2 && this->getCols()==2)
        {
            if (rhs.getCols()==1 && rhs.getRows()==this->getRows())
            {
                
                
                Matrix A(this->getRows(),this->getCols());
                A.matrix[0][0]=rhs.matrix[0][0];
                A.matrix[1][0]=rhs.matrix[1][0];
                A.matrix[0][1]=this->matrix[0][1];
                A.matrix[1][1]=this->matrix[1][1];
            
               this->linearDeterminants[0]=~A;

               Matrix B(this->getRows(),this->getCols());
                B.matrix[0][0]=this->matrix[0][0];
                B.matrix[1][0]=this->matrix[1][0];
                B.matrix[0][1]=rhs.matrix[0][0];
                B.matrix[1][1]=rhs.matrix[1][0];
                
                this->linearDeterminants[1]=~B;

                return this->linearDeterminants;
                

            }else
            {
               cout<<"Error: incorrect number of variables"<<endl;
                return 0;
            }
            
            

        }else if(this->getRows()==3 && this->getCols()==3)
        {
             if (rhs.getCols()==1 && rhs.getRows()==this->getRows())
            {
                
                Matrix A(this->getRows(),this->getCols());
                A.matrix[0][0]=rhs.matrix[0][0];
                A.matrix[1][0]=rhs.matrix[1][0];
                A.matrix[2][0]=rhs.matrix[2][0];
                A.matrix[0][1]=this->matrix[0][1];
                A.matrix[1][1]=this->matrix[1][1];
                A.matrix[2][1]=this->matrix[2][1];
                A.matrix[0][2]=this->matrix[0][2];
                A.matrix[1][2]=this->matrix[1][2];
                A.matrix[2][2]=this->matrix[2][2];

            
               this->linearDeterminants[0]=~A;

               Matrix B(this->getRows(),this->getCols());
                B.matrix[0][0]=this->matrix[0][0];
                B.matrix[1][0]=this->matrix[1][0];
                B.matrix[2][0]=this->matrix[2][0];
                B.matrix[0][1]=rhs.matrix[0][0];
                B.matrix[1][1]=rhs.matrix[1][0];
                B.matrix[2][1]=rhs.matrix[2][0];
                B.matrix[0][2]=this->matrix[0][2];
                B.matrix[1][2]=this->matrix[1][2];
                B.matrix[2][2]=this->matrix[2][2];
                
                this->linearDeterminants[1]=~B;

                Matrix C(this->getRows(),this->getCols());
                C.matrix[0][0]=this->matrix[0][0];
                C.matrix[1][0]=this->matrix[1][0];
                C.matrix[2][0]=this->matrix[2][0];
                C.matrix[0][1]=this->matrix[0][1];
                C.matrix[1][1]=this->matrix[1][1];
                C.matrix[2][1]=this->matrix[2][1];
                C.matrix[0][2]=rhs.matrix[0][0];
                C.matrix[1][2]=rhs.matrix[1][0];
                C.matrix[2][2]=rhs.matrix[2][0];

                
                this->linearDeterminants[2]=~C;


                return this->linearDeterminants;
            }else
            {
                cout<<"Error: incorrect number of variables"<<endl;
                return 0;
            }

        }else{
            cout<<"Error: incorrect number of variables"<<endl;
            return 0;
        }
    }else
    {
        cout<<"Error: non-square matrix provided"<<endl;
        return 0;
    }
        
}

//operator|=

 Matrix Matrix:: operator|=(Matrix &rhs)
 {
     if(this->getRows()==2 && this->getCols()==2)
        {
            if (rhs.getCols()==1 && rhs.getRows()==this->getRows())
            {
                if (this->checkStatus())
                {
                    this->setSolutions(this->getRows());
                    return *this;
                }else
                {
                    if(this->denominator==-0.9)
                            {
                                Matrix obj(this->getRows(),this->getCols());
                                for(int r=0;r<this->getRows();r++)
                                {
                                    for(int c=0;c<this->getCols();c++)
                                    {
                                        obj.matrix[r][c]=this->matrix[r][c];
                                    }
                                }
                                this->denominator=~obj;
                                 if(this->linearDeterminants[0]==-0.9)
                                {
                                    this->linearDeterminants= obj|rhs;
                                }
                            }else if(this->linearDeterminants[0]==-0.9){
                            Matrix obj(this->getRows(),this->getCols());
                                for(int r=0;r<this->getRows();r++)
                                {
                                    for(int c=0;c<this->getCols();c++)
                                    {
                                        obj.matrix[r][c]=this->matrix[r][c];
                                    }
                                }

                                 this->linearDeterminants= obj|rhs;
                             }
                              return *this;
                }
                   
            }else
            {
                cout<<"Error: incorrect number of variables"<<endl;
                return *this;
            }
        }else if(this->getRows()==3 && this->getCols()==3)
        {
             if (rhs.getCols()==1 && rhs.getRows()==this->getRows())
            {
                        if(this->checkStatus())
                        {
                            this->setSolutions(this->getRows());
                             return *this;
                        }else{
                            if(this->denominator==-0.9)
                            {
                                Matrix obj(this->getRows(),this->getCols());
                                for(int r=0;r<this->getRows();r++)
                                {
                                    for(int c=0;c<this->getCols();c++)
                                    {
                                        obj.matrix[r][c]=this->matrix[r][c];
                                    }
                                }
                                this->denominator=~obj;
                                 if(this->linearDeterminants[0]==-0.9)
                                {
                                    this->linearDeterminants= obj|rhs;
                                }
                            }else if(this->linearDeterminants[0]==-0.9){
                            Matrix obj(this->getRows(),this->getCols());
                                for(int r=0;r<this->getRows();r++)
                                {
                                    for(int c=0;c<this->getCols();c++)
                                    {
                                        obj.matrix[r][c]=this->matrix[r][c];
                                    }
                                }

                                 this->linearDeterminants= obj|rhs;
                             }
                              return *this;
                        }
                }else
                {
                    cout<<"Error: incorrect number of variables"<<endl;
                    return *this;
                }

        }else
        {
               cout<<"Error: incorrect number of variables"<<endl;
                return *this;
        }

 }


 //checkstatus

 bool Matrix::checkStatus()
 {
     bool status=true;

     if(this->denominator==-0.9)
     {
         status=false;
         return status;
     }else if(this->linearDeterminants[0]==-0.9)
     {
         status=false;
         return status;
     }
    return status;
 }

 // setsolutions

void Matrix:: setSolutions(unsigned i)
{
    if(this->denominator!=0)
    {    
        this->linearSolutions=new double[i];
        for(int r =0;r<i;r++)
        {
            this->linearSolutions[r]=this->linearDeterminants[r]/this->denominator;
        }
    }else
    {
        cout<<"“Error: division by zero"<<endl;
    }   
}

//destructor

Matrix::~Matrix()
{
    for(int i =0;i<this->rows;i++)
    {
        delete [] matrix[i];
    }

    delete [] matrix; 

    delete [] linearDeterminants;
}

//end of program