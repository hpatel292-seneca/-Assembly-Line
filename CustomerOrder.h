// -name:-Harshil Patel,
// - Seneca student ID:- 148847213,
// - Seneca email:- hpatel292@myseneca.ca
// - date of completion:- 04 April, 2023.
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.


#ifndef SDDS_CUSTOMERORDER_H
#define SDDS_CUSTOMERORDER_H
#include<string>
#include"Station.h"
namespace sdds
{
	struct Item
	{
		std::string m_itemName;
		size_t m_serialNumber{ 0 };
		bool m_isFilled{ false };

		Item(const std::string& src) : m_itemName(src) {};
	};
	class CustomerOrder
	{
		std::string m_name{};
		std::string m_product{};
		size_t m_cntItem{};
		Item** m_lstItem{};
		void add(std::string& str); // used to add item to m_lstItem
		static size_t m_widthField;

	public:
		CustomerOrder();
		CustomerOrder(std::string str);
		// copy operation
		CustomerOrder(const CustomerOrder& order);
		CustomerOrder& operator=(const CustomerOrder& order) = delete;
		// move operation
		CustomerOrder(CustomerOrder&& order) noexcept;
		CustomerOrder& operator=(CustomerOrder&& order) noexcept;
		// delete memory
		void freeMemory();
		// destructor
		~CustomerOrder();
		bool isOrderFilled() const;
		bool isItemFilled(const std::string& itemName) const;
		void fillItem(sdds::Station& station, std::ostream& os);
		void display(std::ostream& os) const;
	};
}

#endif
