#ifndef OPENDNP3CLR_COLLECTION_ADAPTER_H
#define OPENDNP3CLR_COLLECTION_ADAPTER_H

#include <opendnp3/app/parsing/ICollection.h>

#include <vcclr.h>

using namespace Automatak::DNP3::Interface;

using namespace System::Collections::Generic;

namespace Automatak
{
	namespace DNP3
	{
		namespace Adapter
		{

			template <class Source, class Target, class Convert>
			class CollectionAdapter : public opendnp3::IVisitor<Source>
			{
			public:
				CollectionAdapter(const Convert& convert_) : list(gcnew List<Target>()), convert(convert_)
				{
						
				}

				virtual void OnValue(const Source& value) override final
				{
					Target target = convert(value);
					this->list->Add(target);
				}

				IEnumerable<Target>^ GetValues()
				{
					return list;
				}

			private:

				gcroot<System::Collections::Generic::IList<Target>^> list;
				Convert convert;
			};

			template <class Source, class Target, class Convert>
			CollectionAdapter<Source, Target, Convert> CreateAdapter(const Convert& convert)
			{
				return CollectionAdapter<Source, Target, Convert>(convert);
			}

		}
	}
}

#endif
