/**
 * Licensed to Green Energy Corp (www.greenenergycorp.com) under one or
 * more contributor license agreements. See the NOTICE file distributed
 * with this work for additional information regarding copyright ownership.
 * Green Energy Corp licenses this file to you under the Apache License,
 * Version 2.0 (the "License"); you may not use this file except in
 * compliance with the License.  You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 * This project was forked on 01/01/2013 by Automatak, LLC and modifications
 * may have been made to this file. Automatak, LLC licenses these modifications
 * to you under the terms of the License.
 */
#ifndef OPENDNP3_OUTSTATIONSOLICITEDSTATES_H
#define OPENDNP3_OUTSTATIONSOLICITEDSTATES_H

#include "opendnp3/app/APDUHeader.h"
#include "opendnp3/app/APDUWrapper.h"

#include <openpal/util/Uncopyable.h>

namespace opendnp3
{

class OState;

/**
 * Base class for various outstation states
 */
class OutstationSolicitedStateBase
{
public:	

	virtual OutstationSolicitedStateBase* OnConfirm(OState&, const APDUHeader& frag);

	virtual OutstationSolicitedStateBase* OnSendResult(OState&, bool isSucccess);

	virtual OutstationSolicitedStateBase* OnConfirmTimeout(OState&);

	virtual OutstationSolicitedStateBase* OnNewReadRequest(OState&, const APDUHeader& header, const openpal::ReadBufferView& objects);

	virtual OutstationSolicitedStateBase* OnNewNonReadRequest(OState&, const APDUHeader& header, const openpal::ReadBufferView& objects);

	virtual OutstationSolicitedStateBase* OnRepeatNonReadRequest(OState&, const APDUHeader& header, const openpal::ReadBufferView& objects);

protected:

};

class OutstationSolicitedStateIdle : public OutstationSolicitedStateBase, private openpal::Uncopyable
{

public:

	static OutstationSolicitedStateBase& Inst();

	virtual OutstationSolicitedStateBase* OnNewReadRequest(OState&, const APDUHeader& header, const openpal::ReadBufferView& objects) override final;

	virtual OutstationSolicitedStateBase* OnNewNonReadRequest(OState&, const APDUHeader& header, const openpal::ReadBufferView& objects)  override final;

	virtual OutstationSolicitedStateBase* OnRepeatNonReadRequest(OState&, const APDUHeader& header, const openpal::ReadBufferView& objects)  override final;

private:

	static OutstationSolicitedStateIdle instance;

	OutstationSolicitedStateIdle() {}

};


/*
* waiting for a confirm to a solicited read response
*/
class OutstationStateSolicitedConfirmWait : public OutstationSolicitedStateBase, private openpal::Uncopyable
{

public:

	static OutstationSolicitedStateBase& Inst();

	virtual OutstationSolicitedStateBase* OnNewReadRequest(OState&, const APDUHeader& header, const openpal::ReadBufferView& objects) override final;

	virtual OutstationSolicitedStateBase* OnNewNonReadRequest(OState&, const APDUHeader& header, const openpal::ReadBufferView& objects)  override final;	

	virtual OutstationSolicitedStateBase* OnConfirm(OState&, const APDUHeader& frag) override final;

	virtual OutstationSolicitedStateBase* OnConfirmTimeout(OState&) override final;

private:	

	static OutstationStateSolicitedConfirmWait instance;

	OutstationStateSolicitedConfirmWait() {}
};

} //ens ns



#endif

