
class Item
{
private:
    int _id;
    int _value;
    double _media;
    int *_constraints;
public:
    Item(int id, int value, double media, int *constraints)
    {
        this->_id = id;
        this->_value = value;;
        this->_constraints = constraints;
        this->_media = media;
    };
    inline int get_id(){return this->_id;}
    inline int get_value(){ return this->_value;};
    inline double get_media() { return this->_media;};
    inline int *get_Constraints(){return this->_constraints;};
  

    ~Item()
    {
        delete[] this->_constraints;
    };
};